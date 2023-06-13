#include "rpl_whoishost_378.hpp"

/* default constructor */
irc::rpl_whoishost_378::rpl_whoishost_378(void) {
    return;
}

/* destructor */
irc::rpl_whoishost_378::~rpl_whoishost_378(void) {
    return;
}

/* execute command */
bool irc::rpl_whoishost_378::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_whoishost_378::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_whoishost_378::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_whoishost_378());
}
