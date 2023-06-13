#include "rpl_endofmotd_376.hpp"

/* default constructor */
irc::rpl_endofmotd_376::rpl_endofmotd_376(void) {
    return;
}

/* destructor */
irc::rpl_endofmotd_376::~rpl_endofmotd_376(void) {
    return;
}

/* execute command */
bool irc::rpl_endofmotd_376::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_endofmotd_376::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_endofmotd_376::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_endofmotd_376());
}
