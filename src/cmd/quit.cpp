#include "quit.hpp"


/* parametric constructor */
irc::quit::quit(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	std::cout << "quit command created" << std::endl;
    return;
}

/* destructor */
irc::quit::~quit(void) {
    return;
}

/* execute command */
bool irc::quit::execute(void) {
    return false;
}

/* evaluate command */
bool irc::quit::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::quit::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::quit(msg, conn));
}
