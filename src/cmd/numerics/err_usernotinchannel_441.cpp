#include "err_usernotinchannel_441.hpp"

/* default constructor */
irc::err_usernotinchannel_441::err_usernotinchannel_441(void) {
    return;
}

/* destructor */
irc::err_usernotinchannel_441::~err_usernotinchannel_441(void) {
    return;
}

/* execute command */
bool irc::err_usernotinchannel_441::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_usernotinchannel_441::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_usernotinchannel_441::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_usernotinchannel_441());
}
