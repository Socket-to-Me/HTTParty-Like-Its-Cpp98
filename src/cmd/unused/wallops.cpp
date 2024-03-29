#include "wallops.hpp"

/* default constructor */
irc::wallops::wallops(void) {
    return;
}

/* parametric constructor */
irc::wallops::wallops(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::wallops::~wallops(void) {
    return;
}

/* execute command */
bool irc::wallops::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::wallops::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::wallops::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::wallops(std::vector<irc::token> tokens));
}
