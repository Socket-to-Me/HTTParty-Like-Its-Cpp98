#include "rpl_info_371.hpp"

/* default constructor */
irc::rpl_info_371::rpl_info_371(void) {
    return;
}

/* destructor */
irc::rpl_info_371::~rpl_info_371(void) {
    return;
}

/* execute command */
bool irc::rpl_info_371::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_info_371::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_info_371::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_info_371());
}
