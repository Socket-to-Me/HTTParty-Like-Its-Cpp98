#include "rpl_isupport_005.hpp"

/* default constructor */
irc::rpl_isupport_005::rpl_isupport_005(void) {
    return;
}

/* destructor */
irc::rpl_isupport_005::~rpl_isupport_005(void) {
    return;
}

/* execute command */
bool irc::rpl_isupport_005::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_isupport_005::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_isupport_005::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_isupport_005());
}
