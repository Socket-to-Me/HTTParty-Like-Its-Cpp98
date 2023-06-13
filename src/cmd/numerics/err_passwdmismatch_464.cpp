#include "err_passwdmismatch_464.hpp"

/* default constructor */
irc::err_passwdmismatch_464::err_passwdmismatch_464(void) {
    return;
}

/* destructor */
irc::err_passwdmismatch_464::~err_passwdmismatch_464(void) {
    return;
}

/* execute command */
bool irc::err_passwdmismatch_464::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_passwdmismatch_464::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_passwdmismatch_464::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_passwdmismatch_464());
}
