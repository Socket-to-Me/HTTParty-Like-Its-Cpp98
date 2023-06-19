#include "names.hpp"

/* default constructor */
irc::names::names(void) {
    return;
}

/* parametric constructor */
irc::names::names(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::names::~names(void) {
    return;
}

/* execute command */
bool irc::names::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::names::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::names::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::names(std::vector<irc::token> tokens));
}
