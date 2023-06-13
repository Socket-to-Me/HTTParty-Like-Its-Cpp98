#include "rpl_endofstats_219.hpp"

/* default constructor */
irc::rpl_endofstats_219::rpl_endofstats_219(void) {
    return;
}

/* destructor */
irc::rpl_endofstats_219::~rpl_endofstats_219(void) {
    return;
}

/* execute command */
bool irc::rpl_endofstats_219::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_endofstats_219::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_endofstats_219::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_endofstats_219());
}
