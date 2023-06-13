#include "rpl_whoreply_352.hpp"

/* default constructor */
irc::rpl_whoreply_352::rpl_whoreply_352(void) {
    return;
}

/* destructor */
irc::rpl_whoreply_352::~rpl_whoreply_352(void) {
    return;
}

/* execute command */
bool irc::rpl_whoreply_352::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_whoreply_352::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_whoreply_352::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_whoreply_352());
}
