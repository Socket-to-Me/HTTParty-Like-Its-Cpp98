#include "pong.hpp"

/* default constructor */
irc::pong::pong(void) {
    return;
}

/* parametric constructor */
irc::pong::pong(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::pong::~pong(void) {
    return;
}

/* execute command */
bool irc::pong::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::pong::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::pong::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::pong(std::vector<irc::token> tokens));
}
