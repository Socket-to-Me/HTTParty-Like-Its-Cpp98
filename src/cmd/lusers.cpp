#include "lusers.hpp"

/* default constructor */
irc::lusers::lusers(void) {
    return;
}

/* parametric constructor */
irc::lusers::lusers(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::lusers::~lusers(void) {
    return;
}

/* execute command */
bool irc::lusers::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::lusers::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::lusers::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::lusers(std::vector<irc::token> tokens));
}
