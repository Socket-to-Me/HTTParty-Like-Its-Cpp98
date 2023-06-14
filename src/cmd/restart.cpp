#include "restart.hpp"

/* default constructor */
irc::restart::restart(void) {
    return;
}

/* destructor */
irc::restart::~restart(void) {
    return;
}

/* execute command */
bool irc::restart::execute(void) {
    return false;
}

/* evaluate command */
bool irc::restart::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::restart::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::restart());
}
