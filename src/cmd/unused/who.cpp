#include "who.hpp"

/* default constructor */
irc::who::who(void) {
    return;
}

/* parametric constructor */
irc::who::who(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::who::~who(void) {
    return;
}

/* execute command */
bool irc::who::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::who::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::who::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::who(std::vector<irc::token> tokens));
}
