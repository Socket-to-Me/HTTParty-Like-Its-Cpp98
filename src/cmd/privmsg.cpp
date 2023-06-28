#include "privmsg.hpp"


/* parametric constructor */
irc::privmsg::privmsg(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	std::cout << "privmsg command created" << std::endl;
    return;
}

/* destructor */
irc::privmsg::~privmsg(void) {
    return;
}

/* execute command */
bool irc::privmsg::execute(void) {
    return false;
}

/* evaluate command */
bool irc::privmsg::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::privmsg::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::privmsg(msg, conn));
}
