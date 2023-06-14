#include "cap.hpp"

/* default constructor */
irc::cap::cap(void) {
    return;
}

/* destructor */
irc::cap::~cap(void) {
    return;
}

/* execute command */
bool irc::cap::execute(void) {
    return false;
}

/* evaluate command */
bool irc::cap::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::cap::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::cap());
}
