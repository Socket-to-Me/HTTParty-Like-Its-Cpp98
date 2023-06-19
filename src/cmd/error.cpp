#include "error.hpp"

/* default constructor */
irc::error::error(void) {
    return;
}

/* parametric constructor */
irc::error::error(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::error::~error(void) {
    return;
}

/* execute command */
bool irc::error::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::error::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::error::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::error(std::vector<irc::token> tokens));
}
