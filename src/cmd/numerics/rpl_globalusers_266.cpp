#include "rpl_globalusers_266.hpp"

/* default constructor */
irc::rpl_globalusers_266::rpl_globalusers_266(void) {
    return;
}

/* destructor */
irc::rpl_globalusers_266::~rpl_globalusers_266(void) {
    return;
}

/* execute command */
bool irc::rpl_globalusers_266::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_globalusers_266::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_globalusers_266::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_globalusers_266());
}
