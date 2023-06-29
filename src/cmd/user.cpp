#include "user.hpp"


/* parametric constructor */
irc::user::user(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line("[user] command received");
    return;
}


/* destructor */
irc::user::~user(void) {
    return;
}

/* execute command */
bool irc::user::execute(void) {

    _conn.setuser(_user);
    return false;
}

/* evaluate command */
bool irc::user::evaluate(void) {

    const std::vector<std::string>&   params = _msg.get_params();
    std::string user = params.back();

    if (params.size() == 0 || user.length() == 0) {
        _conn.send(irc::numerics::err_needmoreparams_461(_conn));
        return false;
    }
    // else if (params.size() != 2) {
    //     return false;
    // }

    if (_conn.getuser().length()) {
        _conn.send(irc::numerics::err_alreadyregistered_462(_conn));
        return false;
    }

    _user = user;
    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::user::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::user(msg, conn));
}
