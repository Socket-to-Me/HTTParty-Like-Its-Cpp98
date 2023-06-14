#include "info.hpp"

/* default constructor */
irc::info::info(void) {
    return;
}

/* destructor */
irc::info::~info(void) {
    return;
}

/* execute command */
bool irc::info::execute(void) {
    return false;
}

/* evaluate command */
bool irc::info::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::info::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::info());
}
