#include "squit.hpp"

/* default constructor */
irc::squit::squit(void) {
    return;
}

/* destructor */
irc::squit::~squit(void) {
    return;
}

/* execute command */
bool irc::squit::execute(void) {
    return false;
}

/* evaluate command */
bool irc::squit::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::squit::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::squit());
}
