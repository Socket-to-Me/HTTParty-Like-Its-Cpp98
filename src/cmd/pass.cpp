#include "pass.hpp"

/* default constructor */
irc::pass::pass(void) {
    return;
}

/* destructor */
irc::pass::~pass(void) {
    return;
}

/* execute command */
bool irc::pass::execute(void) {
    return false;
}

/* evaluate command */
bool irc::pass::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::pass::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::pass());
}
