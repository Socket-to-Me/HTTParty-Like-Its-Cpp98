#include "err_helpnotfound_524.hpp"

/* default constructor */
irc::err_helpnotfound_524::err_helpnotfound_524(void) {
    return;
}

/* destructor */
irc::err_helpnotfound_524::~err_helpnotfound_524(void) {
    return;
}

/* execute command */
bool irc::err_helpnotfound_524::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_helpnotfound_524::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_helpnotfound_524::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_helpnotfound_524());
}
