#include "err_saslfail_904.hpp"

/* default constructor */
irc::err_saslfail_904::err_saslfail_904(void) {
    return;
}

/* destructor */
irc::err_saslfail_904::~err_saslfail_904(void) {
    return;
}

/* execute command */
bool irc::err_saslfail_904::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_saslfail_904::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_saslfail_904::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_saslfail_904());
}
