#include "err_channelisfull_471.hpp"

/* default constructor */
irc::err_channelisfull_471::err_channelisfull_471(void) {
    return;
}

/* destructor */
irc::err_channelisfull_471::~err_channelisfull_471(void) {
    return;
}

/* execute command */
bool irc::err_channelisfull_471::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_channelisfull_471::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_channelisfull_471::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_channelisfull_471());
}
