#include "rpl_whoisspecial_320.hpp"

/* default constructor */
irc::rpl_whoisspecial_320::rpl_whoisspecial_320(void) {
    return;
}

/* destructor */
irc::rpl_whoisspecial_320::~rpl_whoisspecial_320(void) {
    return;
}

/* execute command */
bool irc::rpl_whoisspecial_320::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_whoisspecial_320::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_whoisspecial_320::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_whoisspecial_320());
}
