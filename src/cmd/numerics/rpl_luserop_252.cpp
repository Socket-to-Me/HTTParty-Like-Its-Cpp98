#include "rpl_luserop_252.hpp"

/* default constructor */
irc::rpl_luserop_252::rpl_luserop_252(void) {
    return;
}

/* destructor */
irc::rpl_luserop_252::~rpl_luserop_252(void) {
    return;
}

/* execute command */
bool irc::rpl_luserop_252::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_luserop_252::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_luserop_252::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_luserop_252());
}
