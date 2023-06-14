#include "who.hpp"

/* default constructor */
irc::who::who(void) {
    return;
}

/* destructor */
irc::who::~who(void) {
    return;
}

/* execute command */
bool irc::who::execute(void) {
    return false;
}

/* evaluate command */
bool irc::who::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::who::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::who());
}
