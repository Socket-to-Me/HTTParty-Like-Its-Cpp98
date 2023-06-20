#include "list.hpp"

/* default constructor */
irc::list::list(void) {
    return;
}

/* parametric constructor */
irc::list::list(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::list::~list(void) {
    return;
}

/* execute command */
bool irc::list::execute(void) {
    return false;
}

/* evaluate command */
bool irc::list::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::list::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::list(tokens));
}
