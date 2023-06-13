#include "rpl_topicwhotime_333.hpp"

/* default constructor */
irc::rpl_topicwhotime_333::rpl_topicwhotime_333(void) {
    return;
}

/* destructor */
irc::rpl_topicwhotime_333::~rpl_topicwhotime_333(void) {
    return;
}

/* execute command */
bool irc::rpl_topicwhotime_333::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_topicwhotime_333::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_topicwhotime_333::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_topicwhotime_333());
}
