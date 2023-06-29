#include "server.hpp"
#include "sstream"

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
: _is_running(true),
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
void irc::server::start(const std::string &ip, int port) {

	// setup server socket
    if (setupSocket(ip, port) != 0) { return; }


	// init logger
	irc::log::init();

	// main server loop
    while (_is_running) {

		irc::log::refresh(_networkname,
						  _version,
						  _creation,
						  _pollfds.size() - 1);

        // pollCount = # fds where events were detected
        // (ptr to array of pollfd strcuts, # elem in array, timeout of 60s)
        int pollCount = poll(&_pollfds[0], _pollfds.size(), 0);

        if (pollCount == -1) {
			if (errno == EINTR) { break; }
			else {
				irc::log::add_line("server poll error");
				break;
			}
		}

        //if (pollCount == 0) {
          //  std::cout << "irc::server > poll timeout" << std::endl;
           // continue; }

		// check server listening socket for recent events
		if (_pollfds[0].revents & POLLIN) {
			accept_new_connection();
		}

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


/* send message to one client */
void irc::server::send(irc::connection &conn, const std::string &message)
{
    // TODO
}


// -- C O M M A N D  U T I L S ---------------------

// bool	irc::server::isConnRegistered(const irc::connection& conn) const {

//     if (!_connections.empty()) {

//         if(std::find(_connections.begin(), _connections.end(), conn) != _connections.end()) {
//             return true;
//         }
//     }
//     return false;
// }

bool	irc::server::isNickInUse(const std::string& nick) const {

    // iterator typedef
    typedef std::map<std::string, irc::connection>::const_iterator const_map_iter;

    if (!_connections.empty()) {

        if (_connections.find(nick) != _connections.end()) {
            return true;
        }
    }
    return false;
}

bool	irc::server::isChannelExist(const std::string& channel) const {

    // iterator typedef
    typedef std::map<std::string, irc::channel>::const_iterator const_map_iter;

    if (!_channels.empty()) {

        if (_channels.find(channel) != _channels.end()) {
            return true;
        }
    }
    return false;
}

void	irc::server::newChannel(const std::string& name) {

    irc::channel    channel(name, "TBD");
    _channels.insert(std::make_pair(name, channel));
}


// -- G E T T E R S ---------------------

irc::channel&	irc::server::getchannel(const std::string& channel) {
    return _channels.find(channel)->second;
}

irc::connection&	irc::server::getconnection(const std::string& nick) {
    return _connections.find(nick)->second;
}

const std::string&	irc::server::getname(void) const {
    return _networkname;
}

const std::string&	irc::server::getversion(void) const {
    return _version;
}

std::string	irc::server::getcreation(void) const {
	return _creation;
}

const std::string&	irc::server::getusermodes(void) const {
    return _usermodes;
}

const std::string&	irc::server::getchannelmodes(void) const {
    return _channelmodes;
}

// -- P R I V A T E  M E T H O D S ----------------------------------------------

/* setup socket */
int irc::server::setupSocket(const std::string &ip, int port)
{

    _socket = ::socket(AF_INET, SOCK_STREAM, 0);
    if (_socket == -1) {
        std::cout << "Failed to create socket." << std::endl;
		return -1;
    }

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &(hint.sin_addr));

    if (bind(_socket, (sockaddr *)&hint, sizeof(hint)) == -1) {
        std::cout << "Failed to bind to IP/Port." << std::endl;
		return -1;
    }

    if (listen(_socket, SOMAXCONN) == -1) {
        std::cout << "Failed to listen." << std::endl;
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


/* accept new pollfd connection */
void irc::server::accept_new_connection(void) {

	irc::log::add_line("\n");
	sockaddr_in client;
	socklen_t clientSize = sizeof(client);
	int clientSocket = accept(_socket, (sockaddr *)&client, &clientSize);

	// check if accept() failed
	if (clientSocket == -1) {
		irc::log::add_line("Failed to accept client connection.");
	}
	else {
		irc::log::add_line("New client connected.");
	}

	add_pollfd(clientSocket);
	irc::connection conn(_pollfds.back());

	conn.read();
	std::string msg;

	do {

		msg = conn.extract_message();

		irc::msg message = irc::parser::parse(msg);

		if (message.have_command() == false) { continue; }

		irc::log::add_line("msg: " + msg);

		// search for command
		irc::cmd_factory::cmd_maker maker = irc::cmd_factory::search(message.get_command());

		// check for invalid command
		if (!maker) { irc::log::add_line("Command not found."); continue; }

		// instantiate new command
		irc::auto_ptr<irc::cmd> cmd = maker(message, conn);

		// evaluate command
		if (cmd->evaluate() == false) { irc::log::add_line("Command evaluation failed."); return; }

		// execute command
		cmd->execute();

	} while (msg.size() > 0);


	if (conn.getnick().length()) {
		irc::log::add_line("New connection: " + conn.getnick());
		conn.init_alive(_networkname);
		_connections.insert(std::make_pair(conn.getnick(), conn));
		conn.send(irc::numerics::rpl_welcome_001(conn));
		conn.send(irc::numerics::rpl_yourhost_002(conn));
		conn.send(irc::numerics::rpl_created_003(conn));
		conn.send(irc::numerics::rpl_myinfo_004(conn));
	}

	irc::log::add_line("\n");
}

void irc::server::handle_active_connections(void) {

    // iterator typedef
    typedef std::map<std::string, irc::connection>::iterator map_iter;

    /* loop over all connections */
    for (map_iter it=_connections.begin(); it!=_connections.end(); ++it) {

		// check if connection is active
		if (it->second.receive() == false) { continue; }

		irc::log::add_line("receive active connection");
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

	// check for dead connections
	for (map_iter it=_connections.begin(); it!=_connections.end(); ++it) {

		if (it->second.is_alive() == false) {
			irc::log::add_line("Connection " + it->first + " is dead.");
			remove_pollfd(it->second.getfd());
			_connections.erase(it);
			break;
		}
	}
}
