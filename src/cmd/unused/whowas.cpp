#include "whowas.hpp"

/* default constructor */
irc::whowas::whowas(void) {
    return;
}

/* parametric constructor */
irc::whowas::whowas(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::whowas::~whowas(void) {
    return;
}

/* execute command */
bool irc::whowas::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::whowas::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::whowas::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::whowas(std::vector<irc::token> tokens));
}
