#include "rpl_bounce_010.hpp"

/* default constructor */
irc::rpl_bounce_010::rpl_bounce_010(void) {
    return;
}

/* destructor */
irc::rpl_bounce_010::~rpl_bounce_010(void) {
    return;
}

/* execute command */
bool irc::rpl_bounce_010::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_bounce_010::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_bounce_010::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_bounce_010());
}
