#include "err_badchanmask_476.hpp"

/* default constructor */
irc::err_badchanmask_476::err_badchanmask_476(void) {
    return;
}

/* destructor */
irc::err_badchanmask_476::~err_badchanmask_476(void) {
    return;
}

/* execute command */
bool irc::err_badchanmask_476::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_badchanmask_476::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_badchanmask_476::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_badchanmask_476());
}
