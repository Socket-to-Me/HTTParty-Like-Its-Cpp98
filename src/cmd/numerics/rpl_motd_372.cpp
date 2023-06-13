#include "rpl_motd_372.hpp"

/* default constructor */
irc::rpl_motd_372::rpl_motd_372(void) {
    return;
}

/* destructor */
irc::rpl_motd_372::~rpl_motd_372(void) {
    return;
}

/* execute command */
bool irc::rpl_motd_372::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_motd_372::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_motd_372::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_motd_372());
}
