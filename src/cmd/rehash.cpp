#include "rehash.hpp"

/* default constructor */
irc::rehash::rehash(void) {
    return;
}

/* destructor */
irc::rehash::~rehash(void) {
    return;
}

/* execute command */
bool irc::rehash::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rehash::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rehash::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rehash());
}
