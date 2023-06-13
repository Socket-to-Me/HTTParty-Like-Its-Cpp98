#include "rpl_whoismodes_379.hpp"

/* default constructor */
irc::rpl_whoismodes_379::rpl_whoismodes_379(void) {
    return;
}

/* destructor */
irc::rpl_whoismodes_379::~rpl_whoismodes_379(void) {
    return;
}

/* execute command */
bool irc::rpl_whoismodes_379::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_whoismodes_379::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_whoismodes_379::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_whoismodes_379());
}
