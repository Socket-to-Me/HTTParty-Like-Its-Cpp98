#include "user.hpp"

/* default constructor */
irc::user::user(void) {
    return;
}

/* parametric constructor */
irc::user::user(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::user::~user(void) {
    return;
}

/* execute command */
bool irc::user::execute(irc::connection& conn) {

    // check both nick and user set

    // check send more than 0 bytes
    if (conn.send(irc::numerics::rpl_welcome_001(conn)) < 0) {
        return false;
    }
    if (conn.send(irc::numerics::rpl_yourhost_002(conn)) < 0) {
        return false;
    }
    if (conn.send(irc::numerics::rpl_created_003(conn)) < 0) {
        return false;
    }
    return true;
}

/* evaluate command */
bool irc::user::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::user::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::user(std::vector<irc::token> tokens));
}
