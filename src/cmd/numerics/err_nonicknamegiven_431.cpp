#include "err_nonicknamegiven_431.hpp"

/* default constructor */
irc::err_nonicknamegiven_431::err_nonicknamegiven_431(void) {
    return;
}

/* destructor */
irc::err_nonicknamegiven_431::~err_nonicknamegiven_431(void) {
    return;
}

/* execute command */
bool irc::err_nonicknamegiven_431::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_nonicknamegiven_431::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_nonicknamegiven_431::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_nonicknamegiven_431());
}
