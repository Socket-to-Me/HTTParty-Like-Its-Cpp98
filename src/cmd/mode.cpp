#include "mode.hpp"

/* default constructor */
irc::mode::mode(void) {
    return;
}

/* parametric constructor */
irc::mode::mode(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::mode::~mode(void) {
    return;
}

/* execute command */
bool irc::mode::execute(void) {
    return false;
}

/* evaluate command */
bool irc::mode::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::mode::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::mode(tokens));
}
