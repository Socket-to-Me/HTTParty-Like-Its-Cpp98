#include "authenticate.hpp"

/* default constructor */
irc::authenticate::authenticate(void) {
    return;
}

/* parametric constructor */
irc::authenticate::authenticate(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::authenticate::~authenticate(void) {
    return;
}

/* execute command */
bool irc::authenticate::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::authenticate::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::authenticate::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::authenticate(std::vector<irc::token> tokens));
}
