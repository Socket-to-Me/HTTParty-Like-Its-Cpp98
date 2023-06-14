#include "wallops.hpp"

/* default constructor */
irc::wallops::wallops(void) {
    return;
}

/* destructor */
irc::wallops::~wallops(void) {
    return;
}

/* execute command */
bool irc::wallops::execute(void) {
    return false;
}

/* evaluate command */
bool irc::wallops::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::wallops::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::wallops());
}
