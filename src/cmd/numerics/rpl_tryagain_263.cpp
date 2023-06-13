#include "rpl_tryagain_263.hpp"

/* default constructor */
irc::rpl_tryagain_263::rpl_tryagain_263(void) {
    return;
}

/* destructor */
irc::rpl_tryagain_263::~rpl_tryagain_263(void) {
    return;
}

/* execute command */
bool irc::rpl_tryagain_263::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_tryagain_263::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_tryagain_263::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_tryagain_263());
}
