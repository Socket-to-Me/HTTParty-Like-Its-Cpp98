#include "rpl_saslsuccess_903.hpp"

/* default constructor */
irc::rpl_saslsuccess_903::rpl_saslsuccess_903(void) {
    return;
}

/* destructor */
irc::rpl_saslsuccess_903::~rpl_saslsuccess_903(void) {
    return;
}

/* execute command */
bool irc::rpl_saslsuccess_903::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_saslsuccess_903::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_saslsuccess_903::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_saslsuccess_903());
}
