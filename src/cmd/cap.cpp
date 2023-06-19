#include "cap.hpp"

/* default constructor */
irc::cap::cap(void) {
    return;
}

/* parametric constructor */
irc::cap::cap(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::cap::~cap(void) {
    return;
}

/* execute command */
bool irc::cap::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::cap::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::cap::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::cap(std::vector<irc::token> tokens));
}
