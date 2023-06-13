#include "rpl_whoisaccount_330.hpp"

/* default constructor */
irc::rpl_whoisaccount_330::rpl_whoisaccount_330(void) {
    return;
}

/* destructor */
irc::rpl_whoisaccount_330::~rpl_whoisaccount_330(void) {
    return;
}

/* execute command */
bool irc::rpl_whoisaccount_330::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_whoisaccount_330::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_whoisaccount_330::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_whoisaccount_330());
}
