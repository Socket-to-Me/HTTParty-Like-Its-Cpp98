#include "time.hpp"

/* default constructor */
irc::time::time(void) {
    return;
}

/* destructor */
irc::time::~time(void) {
    return;
}

/* execute command */
bool irc::time::execute(void) {
    return false;
}

/* evaluate command */
bool irc::time::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::time::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::time());
}
