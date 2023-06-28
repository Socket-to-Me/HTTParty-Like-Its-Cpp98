#include "kick.hpp"


/* parametric constructor */
irc::kick::kick(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	std::cout << "kick command created" << std::endl;
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
