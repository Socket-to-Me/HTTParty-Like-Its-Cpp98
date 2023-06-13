#include "rpl_helptxt_705.hpp"

/* default constructor */
irc::rpl_helptxt_705::rpl_helptxt_705(void) {
    return;
}

/* destructor */
irc::rpl_helptxt_705::~rpl_helptxt_705(void) {
    return;
}

/* execute command */
bool irc::rpl_helptxt_705::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_helptxt_705::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_helptxt_705::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_helptxt_705());
}
