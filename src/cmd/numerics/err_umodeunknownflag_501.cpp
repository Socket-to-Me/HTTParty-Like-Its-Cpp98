#include "err_umodeunknownflag_501.hpp"

/* default constructor */
irc::err_umodeunknownflag_501::err_umodeunknownflag_501(void) {
    return;
}

/* destructor */
irc::err_umodeunknownflag_501::~err_umodeunknownflag_501(void) {
    return;
}

/* execute command */
bool irc::err_umodeunknownflag_501::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_umodeunknownflag_501::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_umodeunknownflag_501::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_umodeunknownflag_501());
}
