#include "topic.hpp"

/* default constructor */
irc::topic::topic(void) {
    return;
}

/* destructor */
irc::topic::~topic(void) {
    return;
}

/* execute command */
bool irc::topic::execute(void) {
    return false;
}

/* evaluate command */
bool irc::topic::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::topic::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::topic());
}
