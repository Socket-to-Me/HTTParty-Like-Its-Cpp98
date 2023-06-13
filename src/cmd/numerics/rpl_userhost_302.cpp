#include "rpl_userhost_302.hpp"

/* default constructor */
irc::rpl_userhost_302::rpl_userhost_302(void) {
    return;
}

/* destructor */
irc::rpl_userhost_302::~rpl_userhost_302(void) {
    return;
}

/* execute command */
bool irc::rpl_userhost_302::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_userhost_302::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_userhost_302::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_userhost_302());
}
