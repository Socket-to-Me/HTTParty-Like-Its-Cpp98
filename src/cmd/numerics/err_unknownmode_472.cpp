#include "err_unknownmode_472.hpp"

/* default constructor */
irc::err_unknownmode_472::err_unknownmode_472(void) {
    return;
}

/* destructor */
irc::err_unknownmode_472::~err_unknownmode_472(void) {
    return;
}

/* execute command */
bool irc::err_unknownmode_472::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_unknownmode_472::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_unknownmode_472::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_unknownmode_472());
}
