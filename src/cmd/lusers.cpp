#include "lusers.hpp"

/* default constructor */
irc::lusers::lusers(void) {
    return;
}

/* destructor */
irc::lusers::~lusers(void) {
    return;
}

/* execute command */
bool irc::lusers::execute(void) {
    return false;
}

/* evaluate command */
bool irc::lusers::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::lusers::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::lusers());
}
