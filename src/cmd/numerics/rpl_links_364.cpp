#include "rpl_links_364.hpp"

/* default constructor */
irc::rpl_links_364::rpl_links_364(void) {
    return;
}

/* destructor */
irc::rpl_links_364::~rpl_links_364(void) {
    return;
}

/* execute command */
bool irc::rpl_links_364::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_links_364::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_links_364::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_links_364());
}
