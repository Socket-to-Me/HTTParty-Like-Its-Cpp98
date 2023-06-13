#include "rpl_unaway_305.hpp"

/* default constructor */
irc::rpl_unaway_305::rpl_unaway_305(void) {
    return;
}

/* destructor */
irc::rpl_unaway_305::~rpl_unaway_305(void) {
    return;
}

/* execute command */
bool irc::rpl_unaway_305::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_unaway_305::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_unaway_305::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_unaway_305());
}
