#include "rpl_whoischannels_319.hpp"

/* default constructor */
irc::rpl_whoischannels_319::rpl_whoischannels_319(void) {
    return;
}

/* destructor */
irc::rpl_whoischannels_319::~rpl_whoischannels_319(void) {
    return;
}

/* execute command */
bool irc::rpl_whoischannels_319::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_whoischannels_319::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_whoischannels_319::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_whoischannels_319());
}
