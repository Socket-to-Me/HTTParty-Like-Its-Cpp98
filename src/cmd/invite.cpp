#include "invite.hpp"

/* default constructor */
irc::invite::invite(void) {
    return;
}

/* destructor */
irc::invite::~invite(void) {
    return;
}

/* execute command */
bool irc::invite::execute(void) {
    return false;
}

/* evaluate command */
bool irc::invite::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::invite::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::invite());
}
