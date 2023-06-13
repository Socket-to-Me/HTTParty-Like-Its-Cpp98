#include "rpl_loggedout_901.hpp"

/* default constructor */
irc::rpl_loggedout_901::rpl_loggedout_901(void) {
    return;
}

/* destructor */
irc::rpl_loggedout_901::~rpl_loggedout_901(void) {
    return;
}

/* execute command */
bool irc::rpl_loggedout_901::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_loggedout_901::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_loggedout_901::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_loggedout_901());
}
