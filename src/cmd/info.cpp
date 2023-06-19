#include "info.hpp"

/* default constructor */
irc::info::info(void) {
    return;
}

/* parametric constructor */
irc::info::info(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::info::~info(void) {
    return;
}

/* execute command */
bool irc::info::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::info::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::info::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::info(std::vector<irc::token> tokens));
}
