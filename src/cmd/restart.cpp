#include "restart.hpp"

/* default constructor */
irc::restart::restart(void) {
    return;
}

/* parametric constructor */
irc::restart::restart(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::restart::~restart(void) {
    return;
}

/* execute command */
bool irc::restart::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::restart::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::restart::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::restart(std::vector<irc::token> tokens));
}
