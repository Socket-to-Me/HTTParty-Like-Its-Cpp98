#include "links.hpp"

/* default constructor */
irc::links::links(void) {
    return;
}

/* destructor */
irc::links::~links(void) {
    return;
}

/* execute command */
bool irc::links::execute(void) {
    return false;
}

/* evaluate command */
bool irc::links::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::links::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::links());
}
