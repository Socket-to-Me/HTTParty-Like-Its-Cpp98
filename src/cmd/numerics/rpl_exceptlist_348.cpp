#include "rpl_exceptlist_348.hpp"

/* default constructor */
irc::rpl_exceptlist_348::rpl_exceptlist_348(void) {
    return;
}

/* destructor */
irc::rpl_exceptlist_348::~rpl_exceptlist_348(void) {
    return;
}

/* execute command */
bool irc::rpl_exceptlist_348::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_exceptlist_348::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_exceptlist_348::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_exceptlist_348());
}
