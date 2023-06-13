#include "rpl_time_391.hpp"

/* default constructor */
irc::rpl_time_391::rpl_time_391(void) {
    return;
}

/* destructor */
irc::rpl_time_391::~rpl_time_391(void) {
    return;
}

/* execute command */
bool irc::rpl_time_391::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_time_391::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_time_391::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_time_391());
}
