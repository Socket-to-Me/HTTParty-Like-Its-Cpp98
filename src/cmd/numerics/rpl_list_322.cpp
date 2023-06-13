#include "rpl_list_322.hpp"

/* default constructor */
irc::rpl_list_322::rpl_list_322(void) {
    return;
}

/* destructor */
irc::rpl_list_322::~rpl_list_322(void) {
    return;
}

/* execute command */
bool irc::rpl_list_322::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_list_322::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_list_322::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_list_322());
}
