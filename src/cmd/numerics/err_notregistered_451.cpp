#include "err_notregistered_451.hpp"

/* default constructor */
irc::err_notregistered_451::err_notregistered_451(void) {
    return;
}

/* destructor */
irc::err_notregistered_451::~err_notregistered_451(void) {
    return;
}

/* execute command */
bool irc::err_notregistered_451::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_notregistered_451::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_notregistered_451::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_notregistered_451());
}
