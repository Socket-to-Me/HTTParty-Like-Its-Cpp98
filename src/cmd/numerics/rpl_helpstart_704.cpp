#include "rpl_helpstart_704.hpp"

/* default constructor */
irc::rpl_helpstart_704::rpl_helpstart_704(void) {
    return;
}

/* destructor */
irc::rpl_helpstart_704::~rpl_helpstart_704(void) {
    return;
}

/* execute command */
bool irc::rpl_helpstart_704::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_helpstart_704::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_helpstart_704::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_helpstart_704());
}
