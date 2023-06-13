#include "err_inviteonlychan_473.hpp"

/* default constructor */
irc::err_inviteonlychan_473::err_inviteonlychan_473(void) {
    return;
}

/* destructor */
irc::err_inviteonlychan_473::~err_inviteonlychan_473(void) {
    return;
}

/* execute command */
bool irc::err_inviteonlychan_473::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_inviteonlychan_473::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_inviteonlychan_473::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_inviteonlychan_473());
}
