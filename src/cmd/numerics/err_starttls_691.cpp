#include "err_starttls_691.hpp"

/* default constructor */
irc::err_starttls_691::err_starttls_691(void) {
    return;
}

/* destructor */
irc::err_starttls_691::~err_starttls_691(void) {
    return;
}

/* execute command */
bool irc::err_starttls_691::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_starttls_691::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_starttls_691::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_starttls_691());
}
