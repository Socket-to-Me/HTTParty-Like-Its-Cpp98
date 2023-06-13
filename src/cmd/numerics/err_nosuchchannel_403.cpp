#include "err_nosuchchannel_403.hpp"

/* default constructor */
irc::err_nosuchchannel_403::err_nosuchchannel_403(void) {
    return;
}

/* destructor */
irc::err_nosuchchannel_403::~err_nosuchchannel_403(void) {
    return;
}

/* execute command */
bool irc::err_nosuchchannel_403::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_nosuchchannel_403::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_nosuchchannel_403::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_nosuchchannel_403());
}
