#include "part.hpp"

/* default constructor */
irc::part::part(void) {
    return;
}

/* parametric constructor */
irc::part::part(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::part::~part(void) {
    return;
}

/* execute command */
bool irc::part::execute(void) {
    return false;
}

/* evaluate command */
bool irc::part::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::part::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::part(tokens));
}
