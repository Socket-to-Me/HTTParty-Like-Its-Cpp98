#include "connect.hpp"

/* default constructor */
irc::connect::connect(void) {
    return;
}

/* destructor */
irc::connect::~connect(void) {
    return;
}

/* execute command */
bool irc::connect::execute(void) {
    return false;
}

/* evaluate command */
bool irc::connect::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::connect::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::connect());
}
