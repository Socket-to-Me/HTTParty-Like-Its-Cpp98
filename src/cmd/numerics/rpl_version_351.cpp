#include "rpl_version_351.hpp"

/* default constructor */
irc::rpl_version_351::rpl_version_351(void) {
    return;
}

/* destructor */
irc::rpl_version_351::~rpl_version_351(void) {
    return;
}

/* execute command */
bool irc::rpl_version_351::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_version_351::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_version_351::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_version_351());
}
