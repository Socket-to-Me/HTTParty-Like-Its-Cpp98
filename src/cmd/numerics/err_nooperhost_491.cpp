#include "err_nooperhost_491.hpp"

/* default constructor */
irc::err_nooperhost_491::err_nooperhost_491(void) {
    return;
}

/* destructor */
irc::err_nooperhost_491::~err_nooperhost_491(void) {
    return;
}

/* execute command */
bool irc::err_nooperhost_491::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_nooperhost_491::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_nooperhost_491::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_nooperhost_491());
}
