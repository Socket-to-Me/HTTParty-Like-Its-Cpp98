#include "kill.hpp"

/* default constructor */
irc::kill::kill(void) {
    return;
}

/* parametric constructor */
irc::kill::kill(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::kill::~kill(void) {
    return;
}

/* execute command */
bool irc::kill::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::kill::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::kill::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::kill(std::vector<irc::token> tokens));
}
