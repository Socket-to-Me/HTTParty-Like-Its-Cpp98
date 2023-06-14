#include "quit.hpp"

/* default constructor */
irc::quit::quit(void) {
    return;
}

/* destructor */
irc::quit::~quit(void) {
    return;
}

/* execute command */
bool irc::quit::execute(void) {
    return false;
}

/* evaluate command */
bool irc::quit::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::quit::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::quit());
}
