#include "err_chanoprivsneeded_482.hpp"

/* default constructor */
irc::err_chanoprivsneeded_482::err_chanoprivsneeded_482(void) {
    return;
}

/* destructor */
irc::err_chanoprivsneeded_482::~err_chanoprivsneeded_482(void) {
    return;
}

/* execute command */
bool irc::err_chanoprivsneeded_482::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_chanoprivsneeded_482::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_chanoprivsneeded_482::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_chanoprivsneeded_482());
}
