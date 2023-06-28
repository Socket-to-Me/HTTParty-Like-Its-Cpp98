#include "mode.hpp"

/* parametric constructor */
irc::mode::mode(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	std::cout << "mode command created" << std::endl;
    return;
}

/* destructor */
irc::mode::~mode(void) {
    return;
}

/* execute command */
bool irc::mode::execute(void) {
    return false;
}

/* evaluate command */
bool irc::mode::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::mode::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::mode(msg, conn));
}
