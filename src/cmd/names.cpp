#include "names.hpp"

/* default constructor */
irc::names::names(void) {
    return;
}

/* destructor */
irc::names::~names(void) {
    return;
}

/* execute command */
bool irc::names::execute(void) {
    return false;
}

/* evaluate command */
bool irc::names::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::names::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::names());
}
