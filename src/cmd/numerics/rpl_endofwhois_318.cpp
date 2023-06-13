#include "rpl_endofwhois_318.hpp"

/* default constructor */
irc::rpl_endofwhois_318::rpl_endofwhois_318(void) {
    return;
}

/* destructor */
irc::rpl_endofwhois_318::~rpl_endofwhois_318(void) {
    return;
}

/* execute command */
bool irc::rpl_endofwhois_318::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_endofwhois_318::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_endofwhois_318::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_endofwhois_318());
}
