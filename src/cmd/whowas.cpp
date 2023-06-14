#include "whowas.hpp"

/* default constructor */
irc::whowas::whowas(void) {
    return;
}

/* destructor */
irc::whowas::~whowas(void) {
    return;
}

/* execute command */
bool irc::whowas::execute(void) {
    return false;
}

/* evaluate command */
bool irc::whowas::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::whowas::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::whowas());
}
