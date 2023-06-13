#include "rpl_statsuptime_242.hpp"

/* default constructor */
irc::rpl_statsuptime_242::rpl_statsuptime_242(void) {
    return;
}

/* destructor */
irc::rpl_statsuptime_242::~rpl_statsuptime_242(void) {
    return;
}

/* execute command */
bool irc::rpl_statsuptime_242::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_statsuptime_242::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_statsuptime_242::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_statsuptime_242());
}
