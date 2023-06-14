#include "user.hpp"

/* default constructor */
irc::user::user(void) {
    return;
}

/* destructor */
irc::user::~user(void) {
    return;
}

/* execute command */
bool irc::user::execute(void) {
    return false;
}

/* evaluate command */
bool irc::user::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::user::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::user());
}
