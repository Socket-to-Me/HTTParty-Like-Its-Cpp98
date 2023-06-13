#include "rpl_whoisoperator_313.hpp"

/* default constructor */
irc::rpl_whoisoperator_313::rpl_whoisoperator_313(void) {
    return;
}

/* destructor */
irc::rpl_whoisoperator_313::~rpl_whoisoperator_313(void) {
    return;
}

/* execute command */
bool irc::rpl_whoisoperator_313::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_whoisoperator_313::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_whoisoperator_313::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_whoisoperator_313());
}
