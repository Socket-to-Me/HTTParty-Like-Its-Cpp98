#include "time.hpp"

/* default constructor */
irc::time::time(void) {
    return;
}

/* parametric constructor */
irc::time::time(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::time::~time(void) {
    return;
}

/* execute command */
bool irc::time::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::time::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::time::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::time(std::vector<irc::token> tokens));
}
