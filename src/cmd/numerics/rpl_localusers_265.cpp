#include "rpl_localusers_265.hpp"

/* default constructor */
irc::rpl_localusers_265::rpl_localusers_265(void) {
    return;
}

/* destructor */
irc::rpl_localusers_265::~rpl_localusers_265(void) {
    return;
}

/* execute command */
bool irc::rpl_localusers_265::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_localusers_265::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_localusers_265::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_localusers_265());
}
