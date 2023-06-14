#include "kick.hpp"

/* default constructor */
irc::kick::kick(void) {
    return;
}

/* destructor */
irc::kick::~kick(void) {
    return;
}

/* execute command */
bool irc::kick::execute(void) {
    return false;
}

/* evaluate command */
bool irc::kick::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::kick::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::kick());
}
