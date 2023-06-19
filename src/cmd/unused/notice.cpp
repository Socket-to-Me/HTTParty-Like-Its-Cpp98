#include "notice.hpp"

/* default constructor */
irc::notice::notice(void) {
    return;
}

/* parametric constructor */
irc::notice::notice(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::notice::~notice(void) {
    return;
}

/* execute command */
bool irc::notice::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::notice::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::notice::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::notice(std::vector<irc::token> tokens));
}
