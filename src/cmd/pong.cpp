#include "pong.hpp"

/* default constructor */
irc::pong::pong(void) {
    return;
}

/* destructor */
irc::pong::~pong(void) {
    return;
}

/* execute command */
bool irc::pong::execute(void) {
    return false;
}

/* evaluate command */
bool irc::pong::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::pong::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::pong());
}
