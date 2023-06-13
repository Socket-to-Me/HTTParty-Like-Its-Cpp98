#include "err_toomanychannels_405.hpp"

/* default constructor */
irc::err_toomanychannels_405::err_toomanychannels_405(void) {
    return;
}

/* destructor */
irc::err_toomanychannels_405::~err_toomanychannels_405(void) {
    return;
}

/* execute command */
bool irc::err_toomanychannels_405::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_toomanychannels_405::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_toomanychannels_405::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_toomanychannels_405());
}
