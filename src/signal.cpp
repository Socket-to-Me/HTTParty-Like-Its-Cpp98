#include "signal.hpp"


// -- S I G N A L -------------------------------------------------------------

// -- private static methods --------------------------------------------------

/* ctrl-c handler */
void irc::signal::handler(int) {

	// get server instance
	irc::server& server = irc::server::instance();

	// stop server
	server.stop();
}


// -- public constructors -----------------------------------------------------

/* default constructor */
irc::signal::signal(void) {
	// set ctrl-c handler
	::signal(SIGINT, handler);
}

/* destructor */
irc::signal::~signal(void) {

}
