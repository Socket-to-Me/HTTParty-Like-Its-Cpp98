#include "rpl_loggedin_900.hpp"

/* default constructor */
irc::rpl_loggedin_900::rpl_loggedin_900(void) {
    return;
}

/* destructor */
irc::rpl_loggedin_900::~rpl_loggedin_900(void) {
    return;
}

/* execute command */
bool irc::rpl_loggedin_900::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_loggedin_900::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_loggedin_900::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_loggedin_900());
}
