#include "stats.hpp"

/* default constructor */
irc::stats::stats(void) {
    return;
}

/* destructor */
irc::stats::~stats(void) {
    return;
}

/* execute command */
bool irc::stats::execute(void) {
    return false;
}

/* evaluate command */
bool irc::stats::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::stats::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::stats());
}
