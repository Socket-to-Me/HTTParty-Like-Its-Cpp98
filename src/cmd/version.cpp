#include "version.hpp"

/* default constructor */
irc::version::version(void) {
    return;
}

/* destructor */
irc::version::~version(void) {
    return;
}

/* execute command */
bool irc::version::execute(void) {
    return false;
}

/* evaluate command */
bool irc::version::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::version::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::version());
}
