#include "user.hpp"

/* default constructor */
irc::user::user(void) {
    return;
}

/* parametric constructor */
irc::user::user(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::user::~user(void) {
    return;
}

/* execute command */
bool irc::user::execute(void) {
    return false;
}

/* evaluate command */
bool irc::user::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::user::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::user(tokens));
}
