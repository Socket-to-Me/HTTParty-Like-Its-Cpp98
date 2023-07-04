#include "lusers.hpp"


/* parametric constructor */
irc::lusers::lusers(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line(
			"["
			+ irc::color::green()
			+ "lusers"
			+ irc::color::reset()
			+ "] command received from: "
			+ irc::color::blue()
			+ _conn.getnick()
			+ irc::color::reset());
	irc::log::print(msg.get_raw());
    return;
}

/* destructor */
irc::lusers::~lusers(void) {
    return;
}

/* execute command */
bool irc::lusers::execute(void) {
    return false;
}

/* evaluate command */
bool irc::lusers::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::lusers::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::lusers(msg, conn));
}
