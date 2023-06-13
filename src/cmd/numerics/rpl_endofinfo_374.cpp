#include "rpl_endofinfo_374.hpp"

/* default constructor */
irc::rpl_endofinfo_374::rpl_endofinfo_374(void) {
    return;
}

/* destructor */
irc::rpl_endofinfo_374::~rpl_endofinfo_374(void) {
    return;
}

/* execute command */
bool irc::rpl_endofinfo_374::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_endofinfo_374::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_endofinfo_374::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_endofinfo_374());
}
