#include "userhost.hpp"

/* default constructor */
irc::userhost::userhost(void) {
    return;
}

/* parametric constructor */
irc::userhost::userhost(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::userhost::~userhost(void) {
    return;
}

/* execute command */
bool irc::userhost::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::userhost::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::userhost::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::userhost(std::vector<irc::token> tokens));
}
