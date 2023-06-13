#include "err_notexttosend_412.hpp"

/* default constructor */
irc::err_notexttosend_412::err_notexttosend_412(void) {
    return;
}

/* destructor */
irc::err_notexttosend_412::~err_notexttosend_412(void) {
    return;
}

/* execute command */
bool irc::err_notexttosend_412::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_notexttosend_412::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_notexttosend_412::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_notexttosend_412());
}
