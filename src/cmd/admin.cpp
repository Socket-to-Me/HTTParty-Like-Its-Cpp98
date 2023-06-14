#include "admin.hpp"

/* default constructor */
irc::admin::admin(void) {
    return;
}

/* destructor */
irc::admin::~admin(void) {
    return;
}

/* execute command */
bool irc::admin::execute(void) {
    return false;
}

/* evaluate command */
bool irc::admin::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::admin::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::admin());
}
