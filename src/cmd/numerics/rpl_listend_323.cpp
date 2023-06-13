#include "rpl_listend_323.hpp"

/* default constructor */
irc::rpl_listend_323::rpl_listend_323(void) {
    return;
}

/* destructor */
irc::rpl_listend_323::~rpl_listend_323(void) {
    return;
}

/* execute command */
bool irc::rpl_listend_323::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_listend_323::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_listend_323::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_listend_323());
}
