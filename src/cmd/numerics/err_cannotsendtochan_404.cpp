#include "err_cannotsendtochan_404.hpp"

/* default constructor */
irc::err_cannotsendtochan_404::err_cannotsendtochan_404(void) {
    return;
}

/* destructor */
irc::err_cannotsendtochan_404::~err_cannotsendtochan_404(void) {
    return;
}

/* execute command */
bool irc::err_cannotsendtochan_404::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_cannotsendtochan_404::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_cannotsendtochan_404::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_cannotsendtochan_404());
}
