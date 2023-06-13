#include "rpl_none_300.hpp"

/* default constructor */
irc::rpl_none_300::rpl_none_300(void) {
    return;
}

/* destructor */
irc::rpl_none_300::~rpl_none_300(void) {
    return;
}

/* execute command */
bool irc::rpl_none_300::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_none_300::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_none_300::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_none_300());
}
