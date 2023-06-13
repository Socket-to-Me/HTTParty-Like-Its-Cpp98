#include "err_notonchannel_442.hpp"

/* default constructor */
irc::err_notonchannel_442::err_notonchannel_442(void) {
    return;
}

/* destructor */
irc::err_notonchannel_442::~err_notonchannel_442(void) {
    return;
}

/* execute command */
bool irc::err_notonchannel_442::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_notonchannel_442::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_notonchannel_442::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_notonchannel_442());
}
