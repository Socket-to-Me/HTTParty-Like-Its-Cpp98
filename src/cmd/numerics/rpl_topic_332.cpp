#include "rpl_topic_332.hpp"

/* default constructor */
irc::rpl_topic_332::rpl_topic_332(void) {
    return;
}

/* destructor */
irc::rpl_topic_332::~rpl_topic_332(void) {
    return;
}

/* execute command */
bool irc::rpl_topic_332::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_topic_332::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_topic_332::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_topic_332());
}
