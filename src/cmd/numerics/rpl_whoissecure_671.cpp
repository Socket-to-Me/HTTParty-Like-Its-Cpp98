#include "rpl_whoissecure_671.hpp"

/* default constructor */
irc::rpl_whoissecure_671::rpl_whoissecure_671(void) {
    return;
}

/* destructor */
irc::rpl_whoissecure_671::~rpl_whoissecure_671(void) {
    return;
}

/* execute command */
bool irc::rpl_whoissecure_671::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_whoissecure_671::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_whoissecure_671::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_whoissecure_671());
}
