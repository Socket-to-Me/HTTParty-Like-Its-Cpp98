#include "admin.hpp"

/* default constructor */
irc::admin::admin(void) {
    return;
}

/* parametric constructor */
irc::admin::admin(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::admin::~admin(void) {
    return;
}

/* execute command */
bool irc::admin::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::admin::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::admin::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::admin(std::vector<irc::token> tokens));
}
