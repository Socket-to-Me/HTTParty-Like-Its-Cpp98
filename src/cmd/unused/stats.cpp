#include "stats.hpp"

/* default constructor */
irc::stats::stats(void) {
    return;
}

/* parametric constructor */
irc::stats::stats(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::stats::~stats(void) {
    return;
}

/* execute command */
bool irc::stats::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::stats::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::stats::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::stats(std::vector<irc::token> tokens));
}
