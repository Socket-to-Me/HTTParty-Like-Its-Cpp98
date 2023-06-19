#include "links.hpp"

/* default constructor */
irc::links::links(void) {
    return;
}

/* parametric constructor */
irc::links::links(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::links::~links(void) {
    return;
}

/* execute command */
bool irc::links::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::links::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::links::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::links(std::vector<irc::token> tokens));
}
