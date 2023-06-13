#include "rpl_whowasuser_314.hpp"

/* default constructor */
irc::rpl_whowasuser_314::rpl_whowasuser_314(void) {
    return;
}

/* destructor */
irc::rpl_whowasuser_314::~rpl_whowasuser_314(void) {
    return;
}

/* execute command */
bool irc::rpl_whowasuser_314::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_whowasuser_314::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_whowasuser_314::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_whowasuser_314());
}
