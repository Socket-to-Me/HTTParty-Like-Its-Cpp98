#include "err_nickcollision_436.hpp"

/* default constructor */
irc::err_nickcollision_436::err_nickcollision_436(void) {
    return;
}

/* destructor */
irc::err_nickcollision_436::~err_nickcollision_436(void) {
    return;
}

/* execute command */
bool irc::err_nickcollision_436::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_nickcollision_436::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_nickcollision_436::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_nickcollision_436());
}
