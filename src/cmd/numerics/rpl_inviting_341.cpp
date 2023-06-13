#include "rpl_inviting_341.hpp"

/* default constructor */
irc::rpl_inviting_341::rpl_inviting_341(void) {
    return;
}

/* destructor */
irc::rpl_inviting_341::~rpl_inviting_341(void) {
    return;
}

/* execute command */
bool irc::rpl_inviting_341::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_inviting_341::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_inviting_341::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_inviting_341());
}
