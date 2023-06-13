#include "err_bannedfromchan_474.hpp"

/* default constructor */
irc::err_bannedfromchan_474::err_bannedfromchan_474(void) {
    return;
}

/* destructor */
irc::err_bannedfromchan_474::~err_bannedfromchan_474(void) {
    return;
}

/* execute command */
bool irc::err_bannedfromchan_474::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_bannedfromchan_474::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_bannedfromchan_474::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_bannedfromchan_474());
}
