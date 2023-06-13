#include "rpl_youreoper_381.hpp"

/* default constructor */
irc::rpl_youreoper_381::rpl_youreoper_381(void) {
    return;
}

/* destructor */
irc::rpl_youreoper_381::~rpl_youreoper_381(void) {
    return;
}

/* execute command */
bool irc::rpl_youreoper_381::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_youreoper_381::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_youreoper_381::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_youreoper_381());
}
