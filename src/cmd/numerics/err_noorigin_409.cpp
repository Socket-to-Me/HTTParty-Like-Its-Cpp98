#include "err_noorigin_409.hpp"

/* default constructor */
irc::err_noorigin_409::err_noorigin_409(void) {
    return;
}

/* destructor */
irc::err_noorigin_409::~err_noorigin_409(void) {
    return;
}

/* execute command */
bool irc::err_noorigin_409::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_noorigin_409::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_noorigin_409::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_noorigin_409());
}
