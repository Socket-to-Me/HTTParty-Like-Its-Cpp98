#include "notice.hpp"

/* default constructor */
irc::notice::notice(void) {
    return;
}

/* destructor */
irc::notice::~notice(void) {
    return;
}

/* execute command */
bool irc::notice::execute(void) {
    return false;
}

/* evaluate command */
bool irc::notice::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::notice::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::notice());
}
