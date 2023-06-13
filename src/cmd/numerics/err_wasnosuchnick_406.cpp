#include "err_wasnosuchnick_406.hpp"

/* default constructor */
irc::err_wasnosuchnick_406::err_wasnosuchnick_406(void) {
    return;
}

/* destructor */
irc::err_wasnosuchnick_406::~err_wasnosuchnick_406(void) {
    return;
}

/* execute command */
bool irc::err_wasnosuchnick_406::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_wasnosuchnick_406::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_wasnosuchnick_406::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_wasnosuchnick_406());
}
