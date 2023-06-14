#include "away.hpp"

/* default constructor */
irc::away::away(void) {
    return;
}

/* destructor */
irc::away::~away(void) {
    return;
}

/* execute command */
bool irc::away::execute(void) {
    return false;
}

/* evaluate command */
bool irc::away::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::away::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::away());
}
