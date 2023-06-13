#include "err_unknownerror_400.hpp"

/* default constructor */
irc::err_unknownerror_400::err_unknownerror_400(void) {
    return;
}

/* destructor */
irc::err_unknownerror_400::~err_unknownerror_400(void) {
    return;
}

/* execute command */
bool irc::err_unknownerror_400::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_unknownerror_400::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_unknownerror_400::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_unknownerror_400());
}
