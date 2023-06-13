#include "err_saslaborted_906.hpp"

/* default constructor */
irc::err_saslaborted_906::err_saslaborted_906(void) {
    return;
}

/* destructor */
irc::err_saslaborted_906::~err_saslaborted_906(void) {
    return;
}

/* execute command */
bool irc::err_saslaborted_906::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_saslaborted_906::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_saslaborted_906::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_saslaborted_906());
}
