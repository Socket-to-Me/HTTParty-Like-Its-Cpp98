#include "pong.hpp"

/* parametric constructor */
irc::pong::pong(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line("[pong] command received");
}

/* destructor */
irc::pong::~pong(void) {
    return;
}

/* execute command */
bool irc::pong::execute(void) {
	_conn.pong();
    return true;
}

/* evaluate command */
bool irc::pong::evaluate(void) {
	// check there is only one parameter
	if (_msg.get_params().size() != 1) {
		// send error message
		_conn.send(irc::numerics::err_needmoreparams_461(_conn));
		return false;
	}
	irc::server& server = irc::server::instance();


	/*
	std::cout << _msg.get_params()[0] << std::endl;
	std::cout << server.getname() << std::endl;
	*/

	/*
	if (_msg.get_params()[0] != server.getname()) {
		// send error message
		std::cout << "INVALID PONG" << std::endl;
		return false;
	}*/

	return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::pong::create(const irc::msg& msg, irc::connection& conn) {
	// create pong command
    return irc::auto_ptr<irc::cmd>(new irc::pong(msg, conn));
}
