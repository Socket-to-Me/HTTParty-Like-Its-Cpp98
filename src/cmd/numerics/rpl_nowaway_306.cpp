#include "rpl_nowaway_306.hpp"

/* default constructor */
irc::rpl_nowaway_306::rpl_nowaway_306(void) {
    return;
}

/* destructor */
irc::rpl_nowaway_306::~rpl_nowaway_306(void) {
    return;
}

/* execute command */
bool irc::rpl_nowaway_306::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_nowaway_306::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_nowaway_306::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_nowaway_306());
}
