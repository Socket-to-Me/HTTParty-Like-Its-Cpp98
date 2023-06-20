#include "quit.hpp"

/* default constructor */
irc::quit::quit(void) {
    return;
}

/* parametric constructor */
irc::quit::quit(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::quit::~quit(void) {
    return;
}

/* execute command */
bool irc::quit::execute(void) {
    return false;
}

/* evaluate command */
bool irc::quit::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::quit::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::quit(tokens));
}
