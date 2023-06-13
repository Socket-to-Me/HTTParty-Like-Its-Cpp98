#include "rpl_notopic_331.hpp"

/* default constructor */
irc::rpl_notopic_331::rpl_notopic_331(void) {
    return;
}

/* destructor */
irc::rpl_notopic_331::~rpl_notopic_331(void) {
    return;
}

/* execute command */
bool irc::rpl_notopic_331::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_notopic_331::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_notopic_331::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_notopic_331());
}
