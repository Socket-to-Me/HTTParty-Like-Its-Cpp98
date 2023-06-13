#include "err_alreadyregistered_462.hpp"

/* default constructor */
irc::err_alreadyregistered_462::err_alreadyregistered_462(void) {
    return;
}

/* destructor */
irc::err_alreadyregistered_462::~err_alreadyregistered_462(void) {
    return;
}

/* execute command */
bool irc::err_alreadyregistered_462::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_alreadyregistered_462::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_alreadyregistered_462::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_alreadyregistered_462());
}
