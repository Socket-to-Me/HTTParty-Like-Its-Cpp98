#include "err_nosuchnick_401.hpp"

/* default constructor */
irc::err_nosuchnick_401::err_nosuchnick_401(void) {
    return;
}

/* destructor */
irc::err_nosuchnick_401::~err_nosuchnick_401(void) {
    return;
}

/* execute command */
bool irc::err_nosuchnick_401::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_nosuchnick_401::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_nosuchnick_401::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_nosuchnick_401());
}
