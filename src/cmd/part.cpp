#include "part.hpp"

/* parametric constructor */
irc::part::part(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line(
			"["
			+ irc::color::green()
			+ "part"
			+ irc::color::reset()
			+ "] command received from: "
			+ irc::color::blue()
			+ _conn.getnick()
			+ irc::color::reset());
	irc::log::print(msg.get_raw());
    return;
}

/* destructor */
irc::part::~part(void) {
    return;
}

/* execute command */
bool irc::part::execute(void) {
    return false;
}

/* evaluate command */
bool irc::part::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::part::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::part(msg, conn));
}
