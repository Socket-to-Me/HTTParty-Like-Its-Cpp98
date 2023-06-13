#include "rpl_luserchannels_254.hpp"

/* default constructor */
irc::rpl_luserchannels_254::rpl_luserchannels_254(void) {
    return;
}

/* destructor */
irc::rpl_luserchannels_254::~rpl_luserchannels_254(void) {
    return;
}

/* execute command */
bool irc::rpl_luserchannels_254::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_luserchannels_254::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_luserchannels_254::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_luserchannels_254());
}
