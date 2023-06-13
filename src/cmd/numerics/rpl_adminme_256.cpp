#include "rpl_adminme_256.hpp"

/* default constructor */
irc::rpl_adminme_256::rpl_adminme_256(void) {
    return;
}

/* destructor */
irc::rpl_adminme_256::~rpl_adminme_256(void) {
    return;
}

/* execute command */
bool irc::rpl_adminme_256::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_adminme_256::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_adminme_256::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_adminme_256());
}
