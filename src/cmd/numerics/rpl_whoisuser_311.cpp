#include "rpl_whoisuser_311.hpp"

/* default constructor */
irc::rpl_whoisuser_311::rpl_whoisuser_311(void) {
    return;
}

/* destructor */
irc::rpl_whoisuser_311::~rpl_whoisuser_311(void) {
    return;
}

/* execute command */
bool irc::rpl_whoisuser_311::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_whoisuser_311::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_whoisuser_311::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_whoisuser_311());
}
