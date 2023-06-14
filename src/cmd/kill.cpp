#include "kill.hpp"

/* default constructor */
irc::kill::kill(void) {
    return;
}

/* destructor */
irc::kill::~kill(void) {
    return;
}

/* execute command */
bool irc::kill::execute(void) {
    return false;
}

/* evaluate command */
bool irc::kill::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::kill::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::kill());
}
