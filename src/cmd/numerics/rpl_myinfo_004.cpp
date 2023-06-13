#include "rpl_myinfo_004.hpp"

/* default constructor */
irc::rpl_myinfo_004::rpl_myinfo_004(void) {
    return;
}

/* destructor */
irc::rpl_myinfo_004::~rpl_myinfo_004(void) {
    return;
}

/* execute command */
bool irc::rpl_myinfo_004::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_myinfo_004::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_myinfo_004::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_myinfo_004());
}
