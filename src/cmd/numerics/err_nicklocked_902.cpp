#include "err_nicklocked_902.hpp"

/* default constructor */
irc::err_nicklocked_902::err_nicklocked_902(void) {
    return;
}

/* destructor */
irc::err_nicklocked_902::~err_nicklocked_902(void) {
    return;
}

/* execute command */
bool irc::err_nicklocked_902::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_nicklocked_902::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_nicklocked_902::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_nicklocked_902());
}
