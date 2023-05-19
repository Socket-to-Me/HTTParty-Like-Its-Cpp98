#include "server.hpp"


// -- S I N G L E T O N  I N S T A N C E --------------------------------------

/* singleton instance */
IRC::Server IRC::Server::_instance = IRC::Server();

/* get singleton instance */
IRC::Server& IRC::Server::instance(void) {
	// return singleton instance
	return _instance;
}


// -- P R I V A T E  C O N S T R U C T O R S ----------------------------------

/* default constructor */
IRC::Server::Server(void) {
	// TODO
}

/* copy constructor */
IRC::Server::Server(const Server& server) {
	// TODO
}

/* destructor */
IRC::Server::~Server(void) {
	// TODO
}


// -- P U B L I C  M E T H O D S ----------------------------------------------

/* start server */
bool IRC::Server::start(const std::string& ip, int port) {

	_socket = ::socket(AF_INET, SOCK_STREAM, 0);
    if (_socket == -1) {
        std::cout << "Failed to create socket.\n";
        return false;
    }

    sockaddr_in hint{};
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &(hint.sin_addr));

    if (bind(_socket, (sockaddr*)&hint, sizeof(hint)) == -1) {
        std::cout << "Failed to bind to IP/Port.\n";
        return false;
    }

    if (listen(_socket, SOMAXCONN) == -1) {
        std::cout << "Failed to listen.\n";
        return false;
    }

    return true;
}

/* stop server */
void IRC::Server::stop(void) {

    for (auto& connection : _conns) {
        connection.close();
    }
    _conns.clear();

    if (_socket != -1) {
        ::close(_socket);
        _socket = -1;
    }

}

/* restart server */
void IRC::Server::restart(void) {
	// TODO
}

/* subscribe client */
void IRC::Server::subscribe(const Client& client) {
	// TODO
}

/* unsubscribe client */
void IRC::Server::unsubscribe(const Client& client) {
	// TODO
}

/* send message to all clients */
void IRC::Server::broadcast(const std::string& message) {
	// TODO
}

// -- P R I V A T E  M E T H O D S ----------------------------------------------

void IRC::Server::acceptConnections(void) {

    while (true) {

        sockaddr_in client{};
        socklen_t clientSize = sizeof(client);
        int clientSocket = accept(_socket, (sockaddr*)&client, &clientSize);
        if (clientSocket == -1) {
            std::cout << "Failed to accept client connection.\n";
            continue;
        }

        IRC::Connection connection(clientSocket);
        _conns.push_back(connection);

        // Handle the new client connection
        handleNewConnection(connection);
	}
}

void IRC::Server::handleNewConnection(IRC::Connection& connection) {

    // Implement your logic to handle the new client connection
    std::cout << "New client connected. Socket: " << connection.get_sd() << "\n";

    // Example: Send a welcome message to the client
    connection.send_message("Welcome to the server!");

    // Example: Receive and process incoming messages from the client
    std::string message = connection.receive_message(1024);
    std::cout << "Received message: " << message << "\n";

}







