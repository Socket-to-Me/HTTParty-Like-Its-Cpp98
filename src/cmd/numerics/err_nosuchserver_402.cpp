#include "err_nosuchserver_402.hpp"

/* default constructor */
irc::err_nosuchserver_402::err_nosuchserver_402(void) {
    return;
}

/* destructor */
irc::err_nosuchserver_402::~err_nosuchserver_402(void) {
    return;
}

/* execute command */
bool irc::err_nosuchserver_402::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_nosuchserver_402::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_nosuchserver_402::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_nosuchserver_402());
}
