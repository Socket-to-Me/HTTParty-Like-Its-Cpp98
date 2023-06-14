#include "nick.hpp"

/* default constructor */
irc::nick::nick(void) {
    return;
}

/* destructor */
irc::nick::~nick(void) {
    return;
}

/* execute command */
bool irc::nick::execute(void) {
    return false;
}

/* evaluate command */
bool irc::nick::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::nick::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::nick());
}
