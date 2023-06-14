#include "mode.hpp"

/* default constructor */
irc::mode::mode(void) {
    return;
}

/* destructor */
irc::mode::~mode(void) {
    return;
}

/* execute command */
bool irc::mode::execute(void) {
    return false;
}

/* evaluate command */
bool irc::mode::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::mode::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::mode());
}
