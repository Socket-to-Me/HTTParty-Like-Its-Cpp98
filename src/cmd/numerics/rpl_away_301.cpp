#include "rpl_away_301.hpp"

/* default constructor */
irc::rpl_away_301::rpl_away_301(void) {
    return;
}

/* destructor */
irc::rpl_away_301::~rpl_away_301(void) {
    return;
}

/* execute command */
bool irc::rpl_away_301::execute(void) {
    return false;
}

/* evaluate command */
bool irc::rpl_away_301::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rpl_away_301::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::rpl_away_301());
}
