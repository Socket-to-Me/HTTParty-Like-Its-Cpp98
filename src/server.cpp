#include "server.hpp"
#include "sstream"

#include <fcntl.h>

void set_non_blocking(int sock) {
    int opts;

    opts = fcntl(sock, F_GETFL);
    if (opts < 0) {
        perror("fcntl(F_GETFL)");
        exit(EXIT_FAILURE);
    }
    opts = (opts | O_NONBLOCK);
    if (fcntl(sock,F_SETFL,opts) < 0) {
        perror("fcntl(F_SETFL)");
        exit(EXIT_FAILURE);
    }
    return;
}


// -- private static members --------------------------------------------------

/* singleton instance */
irc::server irc::server::_instance = irc::server();


// -- public static methods ---------------------------------------------------

/* get singleton instance */
irc::server &irc::server::instance(void) {
    // return singleton instance
    return _instance;
}


// -- private constructors ----------------------------------------------------

/* default constructor */
irc::server::server(void)
:
  _socket(-1),
  _port(0),
  _is_running(true),
  _pollfds(),
  _connections(),
  _channels(),
  _remove_queue(),
  _networkname("httparty.like.its.98"),
  _version("1.1"),
  _usermodes("o"),
  _channelmodes("itkol"),
  _channelmodeswithparams(""),
  _creation(irc::now()) {
}

/* destructor */
irc::server::~server(void) {

	// declare iterator type
	connection_map::iterator it = _connections.begin();

	// loop over all connections and send quit message
	for (; it != _connections.end(); ++it) {
		irc::quit::send(it->second);
	}

	// vector size type
	typedef pollfd_vector::size_type vec_size;
	// loop over all pollfds and close them
	for (vec_size i = 0; i < _pollfds.size(); ++i) {
		if (_pollfds[i].fd != -1) {
			close(_pollfds[i].fd);
		}
	}
}



// -- public methods ----------------------------------------------------------

/* start server */
void irc::server::start(const std::string &ip, const uint16_t port, const char* pass) {

	_password.assign(pass);
	_port = port;

	// setup server socket
    if (setupSocket(ip, port) != 0) { return; }

	// set socket to non-blocking
	set_non_blocking(_socket);

	// init logger
	irc::log::init();

	_pollfds.reserve(1024);

	// main server loop
    while (_is_running) {

		irc::log::refresh(_networkname,
						  _version,
						  _creation,
						  _port,
						  _connections.size(),
						  _channels.size());



		// get number of events
        int pollCount = poll(_pollfds.data(), _pollfds.size(), 0);

		// std::stringstream ss;
		// ss << pollCount;
		// irc::log::add_line("pollCount: " + ss.str());

		if (pollCount == -1) {
			if (errno == EINTR) { break; }
			else {
				irc::log::add_line("server poll error");
				break;
			}
			continue;
		}

		// check server listening socket for recent events
		accept_new_connection();
		// check client sockets for new events
		handle_active_connections();

		usleep(100000);
    }

	irc::log::exit();

	irc::out<3>::print("server stopped");

}

/* stop server */
void irc::server::stop(void) {
	// set running flag to false
	_is_running = false;
}


/* send message to all clients */
bool irc::server::broadcast(const std::string& msg) {

    // Iterator typedef for the map
    typedef std::map<std::string, irc::connection>::const_iterator const_map_iter;

    for (const_map_iter it = _connections.begin(); it != _connections.end(); ++it) {
        if (it->second.send(msg) <= 0) {
            return false;
        }
    }

    return true;
}

// -- C O M M A N D  U T I L S ---------------------

bool	irc::server::isNickInUse(const std::string& nick) const {

    if (!_connections.empty()) {

        if (_connections.find(nick) != _connections.end()) {
            return true;
        }
    }
    return false;
}

bool	irc::server::isChannelExist(const std::string& channel) const {

    if (!_channels.empty()) {

        if (_channels.find(channel) != _channels.end()) {
            return true;
        }
    }
    return false;
}

void irc::server::newChannel(const std::string& name) {

    irc::channel channel(name);
    _channels.insert(std::make_pair(name, channel));
}


// -- public accessors --------------------------------------------------------

/* get channels */
irc::server::channel_map& irc::server::getchannels(void) {
    return _channels;
}


/* get channel */
irc::channel& irc::server::getchannel(const std::string& channel) {
    return _channels.find(channel)->second;
}

/* get connection */
irc::connection& irc::server::getconnection(const std::string& nick) {
    return _connections.find(nick)->second;
}

/* get server name */
const std::string& irc::server::getname(void) const {
    return _networkname;
}

/* get server version */
const std::string& irc::server::getversion(void) const {
    return _version;
}

/* get server creation time */
const std::string& irc::server::getcreation(void) const {
	return _creation;
}

/* get server user modes */
const std::string& irc::server::getusermodes(void) const {
    return _usermodes;
}

/* get server channel modes */
const std::string&	irc::server::getchannelmodes(void) const {
    return _channelmodes;
}

/* get password */
const std::string& irc::server::get_password(void) const {
	return _password;
}

// -- P R I V A T E  M E T H O D S ----------------------------------------------

/* setup socket */
int irc::server::setupSocket(const std::string &ip, int port) {

    _socket = ::socket(AF_INET, SOCK_STREAM, 0);
    if (_socket == -1) {
        std::cout << "Failed to create socket." << std::endl;
		return -1;
    }


	// Enable reuse of the address.
    int yes = 1;
	if (setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
		perror("error: setsockopt");
		close(_socket);
        return -1;
    }

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &(hint.sin_addr));

    if (bind(_socket, (sockaddr *)&hint, sizeof(hint)) == -1) {
		perror("error: bind");
		close(_socket);
		return -1;
    }

    if (listen(_socket, SOMAXCONN) == -1) {
		perror("error: listen");
		close(_socket);
		return -1;
    }

    add_pollfd(_socket);
	return 0;
}

/* add new pollfd connection */
void irc::server::add_pollfd(const int fd) {
	// check for fd validity
    if (fd == -1) {
		irc::log::add_line("Not a valid socket to build pollfd.");
		return; }
	// instantiate new pollfd struct
	pollfd pfd = { fd, POLLIN, 0 };
	// add new pollfd to vector
	_pollfds.push_back(pfd);
}

/* remove pollfd connection */
void irc::server::remove_pollfd(const int fd) {

	// declare iterator
	for (pollfd_vector::iterator it = _pollfds.begin(); it != _pollfds.end(); ++it) {
		// continue if fd doesn't match
		if (it->fd != fd) { continue; }
		// remove pollfd from vector
		_pollfds.erase(it); break;
	}
}

/* setup client socket */
int irc::server::setup_client_socket(void) const {

	sockaddr_in client;

	socklen_t size = sizeof(client);

	int socket = ::accept(_socket, (sockaddr *)&client, &size);

	// check for accept failure
	if (socket == -1) {
		irc::log::add_line(strerror(errno));
		return -1;
	}

	// check for already connected
	for (pollfd_vector::const_iterator it = _pollfds.begin(); it != _pollfds.end(); ++it) {
		if (it->fd == socket) { return -1; }
	}

	// set socket to non-blocking
	set_non_blocking(socket);

	// return socket
	return socket;
}

/* accept new pollfd connection */
void irc::server::accept_new_connection(void) {

	// check for poll errors
	if ((_pollfds[0].revents & POLLERR)
	 || (_pollfds[0].revents & POLLHUP)
	 || (_pollfds[0].revents & POLLNVAL)) {
		irc::log::add_line("\x1b[31mError on pollfd [0].\nexiting\x1b[0m");
		_is_running = false;
		return;
	}

	if (_pollfds[0].revents & POLLIN) {



		int clientSocket = setup_client_socket();

		// check for valid socket
		if (clientSocket == -1) { return; };

		irc::log::print("New client connected.");

		add_pollfd(clientSocket);
		irc::connection conn(_pollfds.back());

		conn.read();
		std::string msg;

		do {

			msg = conn.extract_message();

			// check for empty msg
			if (msg.empty()) { break; }

			irc::msg message = irc::parser::parse(msg);

			if (message.have_command() == false) { continue; }

			// search for command
			irc::cmd_factory::cmd_maker maker = irc::cmd_factory::search(message.get_command());

			// check for invalid command
			if (!maker) { irc::log::print("Command not found."); continue; }

			// instantiate new command
			irc::auto_ptr<irc::cmd> cmd = maker(message, conn);

			// evaluate command
			if (cmd->evaluate() == true) {

				// execute command
				cmd->execute();

			} else {

				irc::log::print("Command evaluation failed.");
			}

		} while (msg.size() > 0);


		// ------------------------------------------- failure

		if (conn.is_registered() == false) { // --- wrong password
			conn.send(irc::numerics::err_passwdmismatch_464(conn));
			close(clientSocket);
			_pollfds.pop_back();

		// ---------------------------------------- duplicate nick
		} else if (conn.getnick().empty() || conn.getuser().empty()) {
			close(clientSocket);
			_pollfds.pop_back();

		} else { // ---------------------------------- success

			irc::log::print("New connection: " + conn.getnick());

			// Add to connection map
			_connections.insert(std::make_pair(conn.getnick(), conn));

			// Registration greeting
			conn.send(irc::numerics::rpl_welcome_001(conn));
			conn.send(irc::numerics::rpl_yourhost_002(conn));
			conn.send(irc::numerics::rpl_created_003(conn));
			conn.send(irc::numerics::rpl_myinfo_004(conn));
			conn.send(irc::numerics::rpl_isupport_005(conn));

		}
	}
}

void irc::server::handle_active_connections(void) {

    // iterator typedef
    typedef std::map<std::string, irc::connection>::iterator map_iter;

    /* loop over all connections */
    for (map_iter it = _connections.begin(); it != _connections.end(); ++it) {

		if (it->second.check_fails()  == true) {
			_remove_queue.push(&it->second);
			continue;
		}
		 ///*|| it->second.dead_routine() == true*/)

		// check if connection is active
		if (it->second.receive() == false) { continue; }


		std::string msg = it->second.extract_message();

		irc::msg message = irc::parser::parse(msg);

		if (message.have_command()) {
			irc::cmd_factory::cmd_maker maker = irc::cmd_factory::search(message.get_command());
			if (maker) {
				irc::auto_ptr<irc::cmd> cmd = maker(message, it->second);
				if (cmd->evaluate() == true) {
					cmd->execute();
				}
			}
		}
    }

	// check for connections to remove
	while (_remove_queue.empty() == false) {
		irc::connection* conn = _remove_queue.front();
		_remove_queue.pop();
		unsubscribe(*conn);
	}

	// check for dead connections --> is dead and deletes
	//for (map_iter it=_connections.begin(); it!=_connections.end(); ++it) {

	//	if (it->second.is_alive() == false) {
	//		irc::log::add_line("Connection " + it->first + " is dead. 💀");
	//		unsubscribe(it->second);
	//		break;
	//	}
	//}
}


/* unsubscribe client connection */
void irc::server::unsubscribe(irc::connection& conn) {




	// remove user from channels
	leave_all_channels(conn);

	int fd = conn.getfd();

	if (fd != -1) {
		// close socket
		close(fd);
	}

	// search for connection in map
	connection_map::iterator it = _connections.find(conn.getnick());

	// check if connection was found
	if (it != _connections.end()) {
		_connections.erase(it); }

	// remove pollfd
	remove_pollfd(fd);

}

/* add to remove queue */
void irc::server::add_to_remove_queue(irc::connection& conn) {
	_remove_queue.push(&conn);
}

/* leave all channels */
void irc::server::leave_all_channels(irc::connection& conn) {

    // iterator typedef
    typedef channel_map::iterator map_iter;

	for (map_iter it=_channels.begin(); it != _channels.end(); ++it) {

        irc::log::print("[" + it->second.getname() + "]");
		it->second.removeUser(conn);
		it->second.broadcast(":" + conn.getnick() + " PART " + it->second.getname() + "\r\n");

	}
}

/* leave all channels */
bool irc::server::isChannelNameValid(const std::string& name) const {

    // not empty
    if (name.empty()) {
        return false;
    }

    // has leading character (#)
    if (name[0] != '#') {
        return false;
    }

    // no ascii space
    if (name.find(" ") != std::string::npos) {
        return false;
    }

    // no comma (,)
    if (name.find(",") != std::string::npos) {
        return false;
    }

    // is printable
    for (size_t i=0; i<name.length(); ++i) {
        if (!isprint(name[i]))
            return false;
	}

	return true;
}
