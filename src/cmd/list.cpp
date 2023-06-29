#include "list.hpp"


/* parametric constructor */
irc::list::list(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line(
			"["
			+ irc::color::green()
			+ "list"
			+ irc::color::reset()
			+ "] command received");
    return;
}

/* destructor */
irc::list::~list(void) {
    return;
}

/* execute command */
bool irc::list::execute(void) {
    return false;
}

/* evaluate command */
bool irc::list::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::list::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::list(msg, conn));
}
