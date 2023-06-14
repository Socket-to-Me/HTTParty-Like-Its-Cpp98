#include "authenticate.hpp"

/* default constructor */
irc::authenticate::authenticate(void) {
    return;
}

/* destructor */
irc::authenticate::~authenticate(void) {
    return;
}

/* execute command */
bool irc::authenticate::execute(void) {
    return false;
}

/* evaluate command */
bool irc::authenticate::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::authenticate::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::authenticate());
}
