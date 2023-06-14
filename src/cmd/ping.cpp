#include "ping.hpp"

/* default constructor */
irc::ping::ping(void) {
    return;
}

/* destructor */
irc::ping::~ping(void) {
    return;
}

/* execute command */
bool irc::ping::execute(void) {
    return false;
}

/* evaluate command */
bool irc::ping::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::ping::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::ping());
}
