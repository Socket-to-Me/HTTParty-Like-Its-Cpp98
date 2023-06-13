#include "rpl_yourhost_002.hpp"

/* default constructor */
irc::rpl_yourhost_002::rpl_yourhost_002(void) {
    return;
}

/* destructor */
irc::rpl_yourhost_002::~rpl_yourhost_002(void) {
    return;
}

/* execute command */
bool irc::rpl_yourhost_002::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_yourhost_002::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_yourhost_002::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_yourhost_002());
}
