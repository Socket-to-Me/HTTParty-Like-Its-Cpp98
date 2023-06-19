#include "connect.hpp"

/* default constructor */
irc::connect::connect(void) {
    return;
}

/* parametric constructor */
irc::connect::connect(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::connect::~connect(void) {
    return;
}

/* execute command */
bool irc::connect::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::connect::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::connect::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::connect(std::vector<irc::token> tokens));
}
