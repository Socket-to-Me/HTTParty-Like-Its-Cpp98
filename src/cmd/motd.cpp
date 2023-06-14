#include "motd.hpp"

/* default constructor */
irc::motd::motd(void) {
    return;
}

/* destructor */
irc::motd::~motd(void) {
    return;
}

/* execute command */
bool irc::motd::execute(void) {
    return false;
}

/* evaluate command */
bool irc::motd::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::motd::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::motd());
}
