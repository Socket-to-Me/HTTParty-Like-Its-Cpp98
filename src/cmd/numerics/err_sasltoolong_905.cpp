#include "err_sasltoolong_905.hpp"

/* default constructor */
irc::err_sasltoolong_905::err_sasltoolong_905(void) {
    return;
}

/* destructor */
irc::err_sasltoolong_905::~err_sasltoolong_905(void) {
    return;
}

/* execute command */
bool irc::err_sasltoolong_905::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_sasltoolong_905::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_sasltoolong_905::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_sasltoolong_905());
}
