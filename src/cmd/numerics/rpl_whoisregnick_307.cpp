#include "rpl_whoisregnick_307.hpp"

/* default constructor */
irc::rpl_whoisregnick_307::rpl_whoisregnick_307(void) {
    return;
}

/* destructor */
irc::rpl_whoisregnick_307::~rpl_whoisregnick_307(void) {
    return;
}

/* execute command */
bool irc::rpl_whoisregnick_307::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_whoisregnick_307::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_whoisregnick_307::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_whoisregnick_307());
}
