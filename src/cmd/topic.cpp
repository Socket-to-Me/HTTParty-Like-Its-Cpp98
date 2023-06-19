#include "topic.hpp"

/* default constructor */
irc::topic::topic(void) {
    return;
}

/* parametric constructor */
irc::topic::topic(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::topic::~topic(void) {
    return;
}

/* execute command */
bool irc::topic::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::topic::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::topic::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::topic(std::vector<irc::token> tokens));
}
