#include "pong.hpp"

/* parametric constructor */
irc::pong::pong(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	 irc::log::add_line(
	 		"["
	 		+ irc::color::green()
	 		+ "pong"
	 		+ irc::color::reset()
	 		+ "] command received from: "
	 		+ irc::color::blue()
	 		+ _conn.getnick()
	 		+ irc::color::reset());
	 //irc::log::print(msg.get_raw());
	return;
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
	// check there is only one parameter (the server name as trailing)
	if (_msg.get_params().empty() == false) {
		return false;
	}
	if (_msg.get_trailing().empty() == true) {
		return false;
	}
	// need to check trailing is a valid server name
	return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::pong::create(const irc::msg& msg, irc::connection& conn) {
	// create pong command
    return irc::auto_ptr<irc::cmd>(new irc::pong(msg, conn));
}
