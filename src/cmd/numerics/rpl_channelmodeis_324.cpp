#include "rpl_channelmodeis_324.hpp"

/* default constructor */
irc::rpl_channelmodeis_324::rpl_channelmodeis_324(void) {
    return;
}

/* destructor */
irc::rpl_channelmodeis_324::~rpl_channelmodeis_324(void) {
    return;
}

/* execute command */
bool irc::rpl_channelmodeis_324::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_channelmodeis_324::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_channelmodeis_324::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_channelmodeis_324());
}
