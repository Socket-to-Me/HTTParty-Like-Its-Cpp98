#include "help.hpp"

/* default constructor */
irc::help::help(void) {
    return;
}

/* destructor */
irc::help::~help(void) {
    return;
}

/* execute command */
bool irc::help::execute(void) {
    return false;
}

/* evaluate command */
bool irc::help::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::help::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::help());
}
