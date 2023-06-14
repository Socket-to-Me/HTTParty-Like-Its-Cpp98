#include "userhost.hpp"

/* default constructor */
irc::userhost::userhost(void) {
    return;
}

/* destructor */
irc::userhost::~userhost(void) {
    return;
}

/* execute command */
bool irc::userhost::execute(void) {
    return false;
}

/* evaluate command */
bool irc::userhost::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::userhost::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::userhost());
}
