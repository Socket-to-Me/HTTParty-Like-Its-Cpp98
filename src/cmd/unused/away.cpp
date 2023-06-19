#include "away.hpp"

/* default constructor */
irc::away::away(void) {
    return;
}

/* parametric constructor */
irc::away::away(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::away::~away(void) {
    return;
}

/* execute command */
bool irc::away::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::away::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::away::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::away(std::vector<irc::token> tokens));
}
