#include "rpl_invexlist_346.hpp"

/* default constructor */
irc::rpl_invexlist_346::rpl_invexlist_346(void) {
    return;
}

/* destructor */
irc::rpl_invexlist_346::~rpl_invexlist_346(void) {
    return;
}

/* execute command */
bool irc::rpl_invexlist_346::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_invexlist_346::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_invexlist_346::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_invexlist_346());
}
