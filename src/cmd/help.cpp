#include "help.hpp"

/* default constructor */
irc::help::help(void) {
    return;
}

/* parametric constructor */
irc::help::help(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::help::~help(void) {
    return;
}

/* execute command */
bool irc::help::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::help::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::help::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::help(std::vector<irc::token> tokens));
}
