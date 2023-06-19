#include "ping.hpp"

/* default constructor */
irc::ping::ping(void) {
    return;
}

/* parametric constructor */
irc::ping::ping(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::ping::~ping(void) {
    return;
}

/* execute command */
bool irc::ping::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::ping::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::ping::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::ping(std::vector<irc::token> tokens));
}
