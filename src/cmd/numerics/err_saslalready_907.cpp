#include "err_saslalready_907.hpp"

/* default constructor */
irc::err_saslalready_907::err_saslalready_907(void) {
    return;
}

/* destructor */
irc::err_saslalready_907::~err_saslalready_907(void) {
    return;
}

/* execute command */
bool irc::err_saslalready_907::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_saslalready_907::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_saslalready_907::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_saslalready_907());
}
