#include "user.hpp"


/* parametric constructor */
irc::user::user(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	std::cout << "user command created" << std::endl;
    return;
}


/* destructor */
irc::user::~user(void) {
    return;
}

/* execute command */
bool irc::user::execute(void) {

    // _conn.setuser(_user);
    return false;
}

/* evaluate command */
bool irc::user::evaluate(void) {

    // std::vector<irc::token>& params = _data.getparams();
    // std::string name = _data.gettrailing();

    // if (params.size() == 0 || name.size() == 0) {
    //     _conn.send(irc::numerics::err_needmoreparams_461(conn));
    //     return false;
    // }
    // else if (params.size() != 3) {
    //     return false;
    // }

    // if (_conn.getuser().size() != 0) {
    //     _conn.send(irc::numerics::err_alreadyregistered_462(_conn));
    //     return false;
    // }

    // _user = user;
    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::user::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::user(msg, conn));
}
