#include "rpl_adminemail_259.hpp"

/* default constructor */
irc::rpl_adminemail_259::rpl_adminemail_259(void) {
    return;
}

/* destructor */
irc::rpl_adminemail_259::~rpl_adminemail_259(void) {
    return;
}

/* execute command */
bool irc::rpl_adminemail_259::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_adminemail_259::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_adminemail_259::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_adminemail_259());
}
