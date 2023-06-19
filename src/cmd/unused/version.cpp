#include "version.hpp"

/* default constructor */
irc::version::version(void) {
    return;
}

/* parametric constructor */
irc::version::version(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::version::~version(void) {
    return;
}

/* execute command */
bool irc::version::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::version::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::version::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::version(std::vector<irc::token> tokens));
}
