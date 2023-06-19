#include "motd.hpp"

/* default constructor */
irc::motd::motd(void) {
    return;
}

/* parametric constructor */
irc::motd::motd(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::motd::~motd(void) {
    return;
}

/* execute command */
bool irc::motd::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::motd::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::motd::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::motd(std::vector<irc::token> tokens));
}
