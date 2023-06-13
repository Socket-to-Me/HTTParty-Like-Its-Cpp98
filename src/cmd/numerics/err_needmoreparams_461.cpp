#include "err_needmoreparams_461.hpp"

/* default constructor */
irc::err_needmoreparams_461::err_needmoreparams_461(void) {
    return;
}

/* destructor */
irc::err_needmoreparams_461::~err_needmoreparams_461(void) {
    return;
}

/* execute command */
bool irc::err_needmoreparams_461::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_needmoreparams_461::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_needmoreparams_461::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_needmoreparams_461());
}
