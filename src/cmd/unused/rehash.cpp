#include "rehash.hpp"

/* default constructor */
irc::rehash::rehash(void) {
    return;
}

/* parametric constructor */
irc::rehash::rehash(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::rehash::~rehash(void) {
    return;
}

/* execute command */
bool irc::rehash::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::rehash::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::rehash::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::rehash(std::vector<irc::token> tokens));
}
