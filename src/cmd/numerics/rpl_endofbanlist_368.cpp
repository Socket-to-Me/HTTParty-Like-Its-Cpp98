#include "rpl_endofbanlist_368.hpp"

/* default constructor */
irc::rpl_endofbanlist_368::rpl_endofbanlist_368(void) {
    return;
}

/* destructor */
irc::rpl_endofbanlist_368::~rpl_endofbanlist_368(void) {
    return;
}

/* execute command */
bool irc::rpl_endofbanlist_368::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_endofbanlist_368::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_endofbanlist_368::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_endofbanlist_368());
}
