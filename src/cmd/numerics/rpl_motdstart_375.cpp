#include "rpl_motdstart_375.hpp"

/* default constructor */
irc::rpl_motdstart_375::rpl_motdstart_375(void) {
    return;
}

/* destructor */
irc::rpl_motdstart_375::~rpl_motdstart_375(void) {
    return;
}

/* execute command */
bool irc::rpl_motdstart_375::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_motdstart_375::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_motdstart_375::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_motdstart_375());
}
