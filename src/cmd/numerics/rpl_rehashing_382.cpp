#include "rpl_rehashing_382.hpp"

/* default constructor */
irc::rpl_rehashing_382::rpl_rehashing_382(void) {
    return;
}

/* destructor */
irc::rpl_rehashing_382::~rpl_rehashing_382(void) {
    return;
}

/* execute command */
bool irc::rpl_rehashing_382::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_rehashing_382::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_rehashing_382::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_rehashing_382());
}
