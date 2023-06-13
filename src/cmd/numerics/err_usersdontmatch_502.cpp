#include "err_usersdontmatch_502.hpp"

/* default constructor */
irc::err_usersdontmatch_502::err_usersdontmatch_502(void) {
    return;
}

/* destructor */
irc::err_usersdontmatch_502::~err_usersdontmatch_502(void) {
    return;
}

/* execute command */
bool irc::err_usersdontmatch_502::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_usersdontmatch_502::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_usersdontmatch_502::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_usersdontmatch_502());
}
