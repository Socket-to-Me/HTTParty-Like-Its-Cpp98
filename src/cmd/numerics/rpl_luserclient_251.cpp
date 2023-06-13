#include "rpl_luserclient_251.hpp"

/* default constructor */
irc::rpl_luserclient_251::rpl_luserclient_251(void) {
    return;
}

/* destructor */
irc::rpl_luserclient_251::~rpl_luserclient_251(void) {
    return;
}

/* execute command */
bool irc::rpl_luserclient_251::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_luserclient_251::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_luserclient_251::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_luserclient_251());
}
