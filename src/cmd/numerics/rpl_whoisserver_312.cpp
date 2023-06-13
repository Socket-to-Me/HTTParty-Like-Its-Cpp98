#include "rpl_whoisserver_312.hpp"

/* default constructor */
irc::rpl_whoisserver_312::rpl_whoisserver_312(void) {
    return;
}

/* destructor */
irc::rpl_whoisserver_312::~rpl_whoisserver_312(void) {
    return;
}

/* execute command */
bool irc::rpl_whoisserver_312::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_whoisserver_312::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_whoisserver_312::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_whoisserver_312());
}
