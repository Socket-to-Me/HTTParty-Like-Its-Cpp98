#include "err_norecipient_411.hpp"

/* default constructor */
irc::err_norecipient_411::err_norecipient_411(void) {
    return;
}

/* destructor */
irc::err_norecipient_411::~err_norecipient_411(void) {
    return;
}

/* execute command */
bool irc::err_norecipient_411::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_norecipient_411::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_norecipient_411::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_norecipient_411());
}
