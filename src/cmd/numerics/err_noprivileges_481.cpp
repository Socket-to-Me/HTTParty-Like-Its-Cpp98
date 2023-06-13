#include "err_noprivileges_481.hpp"

/* default constructor */
irc::err_noprivileges_481::err_noprivileges_481(void) {
    return;
}

/* destructor */
irc::err_noprivileges_481::~err_noprivileges_481(void) {
    return;
}

/* execute command */
bool irc::err_noprivileges_481::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_noprivileges_481::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_noprivileges_481::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_noprivileges_481());
}
