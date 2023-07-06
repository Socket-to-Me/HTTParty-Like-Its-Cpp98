#include "user.hpp"


/* parametric constructor */
irc::user::user(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line(
			"["
			+ irc::color::green()
			+ "user"
			+ irc::color::reset()
			+ "] command received from: "
			+ irc::color::blue()
			+ _conn.getnick()
			+ irc::color::reset());
	irc::log::print(msg.get_raw());
    return;
}


/* destructor */
irc::user::~user(void) {
    return;
}

/* execute command */
bool irc::user::execute(void) {

    _conn.setuser(_user);
    return true;
}

/* evaluate command */
bool irc::user::evaluate(void) {

    if (_msg.have_params() == false) {
        _conn.settarget(_msg.get_command());
        _conn.send(irc::numerics::err_needmoreparams_461(_conn));
        return false;
    }

    const std::vector<std::string>&   params = _msg.get_params();
    std::string user = params[0];

    if (_conn.getuser().length()) {
        _conn.send(irc::numerics::err_alreadyregistered_462(_conn));
    }

    _user = user;
    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::user::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::user(msg, conn));
}
