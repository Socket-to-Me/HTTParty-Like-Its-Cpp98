#include "rpl_luserunknown_253.hpp"

/* default constructor */
irc::rpl_luserunknown_253::rpl_luserunknown_253(void) {
    return;
}

/* destructor */
irc::rpl_luserunknown_253::~rpl_luserunknown_253(void) {
    return;
}

/* execute command */
bool irc::rpl_luserunknown_253::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_luserunknown_253::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_luserunknown_253::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_luserunknown_253());
}
