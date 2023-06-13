#include "rpl_namreply_353.hpp"

/* default constructor */
irc::rpl_namreply_353::rpl_namreply_353(void) {
    return;
}

/* destructor */
irc::rpl_namreply_353::~rpl_namreply_353(void) {
    return;
}

/* execute command */
bool irc::rpl_namreply_353::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_namreply_353::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_namreply_353::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_namreply_353());
}
