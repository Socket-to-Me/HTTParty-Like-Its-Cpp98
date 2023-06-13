#include "err_erroneusnickname_432.hpp"

/* default constructor */
irc::err_erroneusnickname_432::err_erroneusnickname_432(void) {
    return;
}

/* destructor */
irc::err_erroneusnickname_432::~err_erroneusnickname_432(void) {
    return;
}

/* execute command */
bool irc::err_erroneusnickname_432::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_erroneusnickname_432::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_erroneusnickname_432::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_erroneusnickname_432());
}
