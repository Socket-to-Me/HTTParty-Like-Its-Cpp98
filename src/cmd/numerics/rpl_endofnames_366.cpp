#include "rpl_endofnames_366.hpp"

/* default constructor */
irc::rpl_endofnames_366::rpl_endofnames_366(void) {
    return;
}

/* destructor */
irc::rpl_endofnames_366::~rpl_endofnames_366(void) {
    return;
}

/* execute command */
bool irc::rpl_endofnames_366::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_endofnames_366::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_endofnames_366::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_endofnames_366());
}
