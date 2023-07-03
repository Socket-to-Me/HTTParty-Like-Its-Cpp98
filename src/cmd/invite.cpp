#include "invite.hpp"

/* parametric constructor */
irc::invite::invite(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line(
			"["
			+ irc::color::green()
			+ "invite"
			+ irc::color::reset()
			+ "] command received from: "
			+ irc::color::blue()
			+ _conn.getnick()
			+ irc::color::reset());
    return;
}

/* destructor */
irc::invite::~invite(void) {
    return;
}

/* execute command */
bool irc::invite::execute(void) {
    return false;
}

/* evaluate command */
bool irc::invite::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::invite::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::invite(msg, conn));
}
