#include "oper.hpp"

/* default constructor */
irc::oper::oper(void) {
    return;
}

/* destructor */
irc::oper::~oper(void) {
    return;
}

/* execute command */
bool irc::oper::execute(void) {
    return false;
}

/* evaluate command */
bool irc::oper::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::oper::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::oper());
}
