#include "nick.hpp"

/* default constructor */
irc::nick::nick(void) {
    return;
}

/* parametric constructor */
irc::nick::nick(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::nick::~nick(void) {
    return;
}

/* execute command */
bool irc::nick::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::nick::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::nick::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::nick(std::vector<irc::token> tokens));
}
