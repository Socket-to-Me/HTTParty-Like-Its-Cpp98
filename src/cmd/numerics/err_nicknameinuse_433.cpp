#include "err_nicknameinuse_433.hpp"

/* default constructor */
irc::err_nicknameinuse_433::err_nicknameinuse_433(void) {
    return;
}

/* destructor */
irc::err_nicknameinuse_433::~err_nicknameinuse_433(void) {
    return;
}

/* execute command */
bool irc::err_nicknameinuse_433::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_nicknameinuse_433::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_nicknameinuse_433::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_nicknameinuse_433());
}
