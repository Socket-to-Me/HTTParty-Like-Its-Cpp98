#include "err_noprivs_723.hpp"

/* default constructor */
irc::err_noprivs_723::err_noprivs_723(void) {
    return;
}

/* destructor */
irc::err_noprivs_723::~err_noprivs_723(void) {
    return;
}

/* execute command */
bool irc::err_noprivs_723::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_noprivs_723::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_noprivs_723::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_noprivs_723());
}
