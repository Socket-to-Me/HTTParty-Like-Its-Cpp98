#include "rpl_invitelist_336.hpp"

/* default constructor */
irc::rpl_invitelist_336::rpl_invitelist_336(void) {
    return;
}

/* destructor */
irc::rpl_invitelist_336::~rpl_invitelist_336(void) {
    return;
}

/* execute command */
bool irc::rpl_invitelist_336::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_invitelist_336::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_invitelist_336::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_invitelist_336());
}
