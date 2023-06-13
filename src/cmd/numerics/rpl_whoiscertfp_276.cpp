#include "rpl_whoiscertfp_276.hpp"

/* default constructor */
irc::rpl_whoiscertfp_276::rpl_whoiscertfp_276(void) {
    return;
}

/* destructor */
irc::rpl_whoiscertfp_276::~rpl_whoiscertfp_276(void) {
    return;
}

/* execute command */
bool irc::rpl_whoiscertfp_276::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_whoiscertfp_276::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_whoiscertfp_276::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_whoiscertfp_276());
}
