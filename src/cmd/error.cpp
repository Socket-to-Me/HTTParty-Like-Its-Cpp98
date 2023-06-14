#include "error.hpp"

/* default constructor */
irc::error::error(void) {
    return;
}

/* destructor */
irc::error::~error(void) {
    return;
}

/* execute command */
bool irc::error::execute(void) {
    return false;
}

/* evaluate command */
bool irc::error::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::error::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::error());
}
