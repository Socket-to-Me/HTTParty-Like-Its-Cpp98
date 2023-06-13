#include "rpl_creationtime_329.hpp"

/* default constructor */
irc::rpl_creationtime_329::rpl_creationtime_329(void) {
    return;
}

/* destructor */
irc::rpl_creationtime_329::~rpl_creationtime_329(void) {
    return;
}

/* execute command */
bool irc::rpl_creationtime_329::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_creationtime_329::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_creationtime_329::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_creationtime_329());
}
