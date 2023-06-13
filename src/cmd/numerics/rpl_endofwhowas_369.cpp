#include "rpl_endofwhowas_369.hpp"

/* default constructor */
irc::rpl_endofwhowas_369::rpl_endofwhowas_369(void) {
    return;
}

/* destructor */
irc::rpl_endofwhowas_369::~rpl_endofwhowas_369(void) {
    return;
}

/* execute command */
bool irc::rpl_endofwhowas_369::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_endofwhowas_369::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_endofwhowas_369::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_endofwhowas_369());
}
