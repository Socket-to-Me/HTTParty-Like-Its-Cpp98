#include "kick.hpp"


/* parametric constructor */
irc::kick::kick(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line(
			"["
			+ irc::color::green()
			+ "kick"
			+ irc::color::reset()
			+ "] command received from: "
			+ irc::color::blue()
			+ _conn.getnick()
			+ irc::color::reset());
    return;
}

/* destructor */
irc::kick::~kick(void) {
    return;
}

/* execute command */
bool irc::kick::execute(void) {
    return false;
}

/* evaluate command */
bool irc::kick::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::kick::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::kick(msg, conn));
}
