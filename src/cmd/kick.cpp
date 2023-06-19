#include "kick.hpp"

/* default constructor */
irc::kick::kick(void) {
    return;
}

/* parametric constructor */
irc::kick::kick(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::kick::~kick(void) {
    return;
}

/* execute command */
bool irc::kick::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::kick::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::kick::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::kick(std::vector<irc::token> tokens));
}
