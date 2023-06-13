#include "rpl_starttls_670.hpp"

/* default constructor */
irc::rpl_starttls_670::rpl_starttls_670(void) {
    return;
}

/* destructor */
irc::rpl_starttls_670::~rpl_starttls_670(void) {
    return;
}

/* execute command */
bool irc::rpl_starttls_670::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_starttls_670::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_starttls_670::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_starttls_670());
}
