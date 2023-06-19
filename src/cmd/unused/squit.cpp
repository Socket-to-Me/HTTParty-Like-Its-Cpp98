#include "squit.hpp"

/* default constructor */
irc::squit::squit(void) {
    return;
}

/* parametric constructor */
irc::squit::squit(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::squit::~squit(void) {
    return;
}

/* execute command */
bool irc::squit::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::squit::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::squit::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::squit(std::vector<irc::token> tokens));
}
