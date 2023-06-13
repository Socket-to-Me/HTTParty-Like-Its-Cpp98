#include "rpl_banlist_367.hpp"

/* default constructor */
irc::rpl_banlist_367::rpl_banlist_367(void) {
    return;
}

/* destructor */
irc::rpl_banlist_367::~rpl_banlist_367(void) {
    return;
}

/* execute command */
bool irc::rpl_banlist_367::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_banlist_367::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_banlist_367::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_banlist_367());
}
