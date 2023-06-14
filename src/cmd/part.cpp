#include "part.hpp"

/* default constructor */
irc::part::part(void) {
    return;
}

/* destructor */
irc::part::~part(void) {
    return;
}

/* execute command */
bool irc::part::execute(void) {
    return false;
}

/* evaluate command */
bool irc::part::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::part::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::part());
}
