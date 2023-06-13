#include "err_badchannelkey_475.hpp"

/* default constructor */
irc::err_badchannelkey_475::err_badchannelkey_475(void) {
    return;
}

/* destructor */
irc::err_badchannelkey_475::~err_badchannelkey_475(void) {
    return;
}

/* execute command */
bool irc::err_badchannelkey_475::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_badchannelkey_475::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_badchannelkey_475::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_badchannelkey_475());
}
