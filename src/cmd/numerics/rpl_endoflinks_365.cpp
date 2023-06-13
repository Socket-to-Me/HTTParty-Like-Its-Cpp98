#include "rpl_endoflinks_365.hpp"

/* default constructor */
irc::rpl_endoflinks_365::rpl_endoflinks_365(void) {
    return;
}

/* destructor */
irc::rpl_endoflinks_365::~rpl_endoflinks_365(void) {
    return;
}

/* execute command */
bool irc::rpl_endoflinks_365::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_endoflinks_365::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_endoflinks_365::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_endoflinks_365());
}
