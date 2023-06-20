#include "invite.hpp"

/* default constructor */
irc::invite::invite(void) {
    return;
}

/* parametric constructor */
irc::invite::invite(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::invite::~invite(void) {
    return;
}

/* execute command */
bool irc::invite::execute(void) {
    return false;
}

/* evaluate command */
bool irc::invite::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::invite::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::invite(tokens));
}
