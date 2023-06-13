#include "rpl_endofhelp_706.hpp"

/* default constructor */
irc::rpl_endofhelp_706::rpl_endofhelp_706(void) {
    return;
}

/* destructor */
irc::rpl_endofhelp_706::~rpl_endofhelp_706(void) {
    return;
}

/* execute command */
bool irc::rpl_endofhelp_706::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_endofhelp_706::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_endofhelp_706::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_endofhelp_706());
}
