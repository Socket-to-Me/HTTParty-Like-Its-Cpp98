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
void IRC::Server::start(void) {
	// TODO
}

/* stop server */
void IRC::Server::stop(void) {
	// TODO
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



















