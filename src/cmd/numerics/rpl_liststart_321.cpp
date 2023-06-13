#include "rpl_liststart_321.hpp"

/* default constructor */
irc::rpl_liststart_321::rpl_liststart_321(void) {
    return;
}

/* destructor */
irc::rpl_liststart_321::~rpl_liststart_321(void) {
    return;
}

/* execute command */
bool irc::rpl_liststart_321::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_liststart_321::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_liststart_321::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_liststart_321());
}
