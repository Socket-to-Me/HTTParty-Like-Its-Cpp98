#include "err_useronchannel_443.hpp"

/* default constructor */
irc::err_useronchannel_443::err_useronchannel_443(void) {
    return;
}

/* destructor */
irc::err_useronchannel_443::~err_useronchannel_443(void) {
    return;
}

/* execute command */
bool irc::err_useronchannel_443::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_useronchannel_443::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_useronchannel_443::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_useronchannel_443());
}
