#include "rpl_statscommands_212.hpp"

/* default constructor */
irc::rpl_statscommands_212::rpl_statscommands_212(void) {
    return;
}

/* destructor */
irc::rpl_statscommands_212::~rpl_statscommands_212(void) {
    return;
}

/* execute command */
bool irc::rpl_statscommands_212::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_statscommands_212::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_statscommands_212::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_statscommands_212());
}
