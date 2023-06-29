#include "server.hpp"
#include "sstream"

// -- S I N G L E T O N  I N S T A N C E --------------------------------------

/* singleton instance */
irc::server irc::server::_instance = irc::server();

/* get singleton instance */
irc::server &irc::server::instance(void) {
    // return singleton instance
    return _instance;
}


// -- P R I V A T E  C O N S T R U C T O R S ----------------------------------

/* default constructor */
irc::server::server(void)
: _is_running(false),
  _networkname("httparty.like.its.98"),
  _version("1.1"),
  _usermodes("oOiwscrknfbghexzSjFI"),
  _channelmodes("itlkob"),
  _channelmodeswithparams("bkohv"),
  _creation(std::time(nullptr)) {
}

/* destructor */
irc::server::~server(void) {
	// vector size type
	typedef std::vector<struct pollfd>::size_type vec_size;


	// loop over all pollfds and close them
	for (vec_size i = 0; i < _pollfds.size(); ++i) {
		if (_pollfds[i].fd != -1) {
			close(_pollfds[i].fd);
		}
	}
}


// -- P U B L I C  M E T H O D S ----------------------------------------------

/* start server */
void irc::server::start(const std::string &ip, int port) {

    setupSocket(ip, port);
    addPollfd(_socket);

	_is_running = true;


    while (_is_running) {

        // pollCount = # fds where events were detected
        // (ptr to array of pollfd strcuts, # elem in array, timeout of 60s)
        int pollCount = poll(&_pollfds[0], _pollfds.size(), 60000);

        if (pollCount == -1) {
			if (errno == EINTR) { break; }
			else {
				std::cout << "irc::server > poll error" << std::endl;
				break;
			}
		}
        if (pollCount == 0) {
            std::cout << "irc::server > poll timeout" << std::endl;
            continue; }

        // check server socket for new connections
        accept_new_connection();

        // check client sockets for new events
        handle_active_connections();

    }


	irc::out<3>::print("irc::server", " > server stopped");

}

/* stop server */
void irc::server::stop(void) {
	// set running flag to false
	_is_running = false;
}

/* restart server */
void irc::server::restart(void)
{
    // TODO
}

/* subscribe client */
void irc::server::subscribe(const irc::connection &conn)
{
    // TODO
}

/* unsubscribe client */
void irc::server::unsubscribe(const irc::connection &conn)
{
    // TODO
}

/* send message to all clients */
void irc::server::broadcast(const std::string &message)
{
    // TODO
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


// -- G E T T E R S ---------------------

irc::channel&	irc::server::getchannel(const std::string& channel) {
    return _channels.find(channel)->second;
}

const std::string&	irc::server::getname(void) const {
    return _networkname;
}

const std::string&	irc::server::getversion(void) const {
    return _version;
}

std::string	irc::server::getcreation(void) const {
    std::string str;
    std::stringstream ss;
    ss << _creation;
    ss >> str;
    return str;
}

const std::string&	irc::server::getusermodes(void) const {
    return _usermodes;
}

const std::string&	irc::server::getchannelmodes(void) const {
    return _channelmodes;
}

// -- P R I V A T E  M E T H O D S ----------------------------------------------

/* setup socket */
void irc::server::setupSocket(const std::string &ip, int port)
{

    _socket = ::socket(AF_INET, SOCK_STREAM, 0);
    if (_socket == -1)
    {
        std::cout << "Failed to create socket." << std::endl;
        // throw std::exception("Failed to create socket.");
    }

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &(hint.sin_addr));

    if (bind(_socket, (sockaddr *)&hint, sizeof(hint)) == -1)
    {
        std::cout << "Failed to bind to IP/Port." << std::endl;
        // throw std::exception("Failed to bind to IP/Port.");
    }

    if (listen(_socket, SOMAXCONN) == -1)
    {
        std::cout << "Failed to listen." << std::endl;
        // throw std::exception("Failed to listen.");
    }
}

/* add new fd to back of pollfds vector */
void irc::server::addPollfd(int fd)
{
    if (fd != -1)
    {
        pollfd pfd;

        pfd.fd = fd;
        pfd.events = POLLIN;
        pfd.revents = 0;

        _pollfds.push_back(pfd);
    }
    else
    {
        std::cout << "Not a valid socket to build pollfd." << std::endl;
        // throw std::exception("Not a valid socket to build pollfd.");
    }
}

/* accept new pollfd connection */
void irc::server::accept_new_connection(void) {


    // check server listening socket for recent events
    if (_pollfds[0].revents & POLLIN) {


        sockaddr_in client;
        socklen_t clientSize = sizeof(client);
        int clientSocket = accept(_socket, (sockaddr *)&client, &clientSize);

		// check if accept() failed
		if (clientSocket == -1) {
			std::cout << "Failed to accept client connection." << std::endl;
		}
		else {
			std::cout << "\x1b[32m" << "New client connected." << "\x1b[0m" << std::endl;
		}

        addPollfd(clientSocket);
        irc::connection conn(_pollfds.back());

		conn.read();
		std::string msg;

		do {

			msg = conn.extract_message();

			irc::msg message = irc::parser::parse(msg);

			if (message.have_command()) {
				irc::cmd_factory::cmd_maker maker = irc::cmd_factory::search(message.get_command());
				if (maker) {
					irc::auto_ptr<irc::cmd> cmd = maker(message, conn);
					if (cmd->evaluate() == true) {
						cmd->execute();
					}
					else {
						std::cout << "Error during registration." << std::endl;
                        return;
                    }
				}
			}

		} while (msg.size() > 0);

        if (conn.getnick().length()) {

            _connections.insert(std::make_pair(conn.getnick(), conn));
            conn.send(irc::numerics::rpl_welcome_001(conn));
            conn.send(irc::numerics::rpl_yourhost_002(conn));
            conn.send(irc::numerics::rpl_created_003(conn));
		}

    }
}

void irc::server::handle_active_connections(void) {

    // iterator typedef
    typedef std::map<std::string, irc::connection>::iterator map_iter;

    /* loop over all connections */
    for (map_iter it=_connections.begin(); it!=_connections.end(); ++it) {

        if (it->second.receive()) {

			std::cout << "receive active connection" << std::endl;
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
    }
}
