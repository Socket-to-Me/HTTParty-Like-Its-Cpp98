#include "err_cantkillserver_483.hpp"

/* default constructor */
irc::err_cantkillserver_483::err_cantkillserver_483(void) {
    return;
}

/* destructor */
irc::err_cantkillserver_483::~err_cantkillserver_483(void) {
    return;
}

/* execute command */
bool irc::err_cantkillserver_483::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_cantkillserver_483::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_cantkillserver_483::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_cantkillserver_483());
}
