#include "err_invalidkey_525.hpp"

/* default constructor */
irc::err_invalidkey_525::err_invalidkey_525(void) {
    return;
}

/* destructor */
irc::err_invalidkey_525::~err_invalidkey_525(void) {
    return;
}

/* execute command */
bool irc::err_invalidkey_525::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_invalidkey_525::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_invalidkey_525::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_invalidkey_525());
}
