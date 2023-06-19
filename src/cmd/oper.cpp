#include "oper.hpp"

/* default constructor */
irc::oper::oper(void) {
    return;
}

/* parametric constructor */
irc::oper::oper(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::oper::~oper(void) {
    return;
}

/* execute command */
bool irc::oper::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::oper::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::oper::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::oper(std::vector<irc::token> tokens));
}
