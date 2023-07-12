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

    // irc::server&    serv = irc::server.instance();

    // // ------------------------------------------- failure

    // if (conn.is_registered() == false) { // --- wrong password
    //     conn.send(irc::numerics::err_passwdmismatch_464(conn));
    //     close(clientSocket);
    //     _pollfds.pop_back();

    // // ---------------------------------------- duplicate nick
    // } else if (conn.getnick().empty() || conn.getuser().empty()) {
    //     close(clientSocket);
    //     _pollfds.pop_back();

    // } else { // ---------------------------------- success

    //     irc::log::print("New connection: " + conn.getnick());

    //     // Add to connection map
    //     _connections.insert(std::make_pair(conn.getnick(), conn));

    //     // Registration greeting
    //     conn.send(irc::numerics::rpl_welcome_001(conn));
    //     conn.send(irc::numerics::rpl_yourhost_002(conn));
    //     conn.send(irc::numerics::rpl_created_003(conn));
    //     conn.send(irc::numerics::rpl_myinfo_004(conn));
    //     conn.send(irc::numerics::rpl_isupport_005(conn));

    // }

    _conn.setuser(_user);
    _conn.sethost(_host);
    _conn.setrealname(_realname);

    return true;
}

/* evaluate command */
bool irc::user::evaluate(void) {

    if (_msg.have_params() == false || _msg.have_trailing() == false) {
        _conn.settarget(_msg.get_command());
        _conn.send(irc::numerics::err_needmoreparams_461(_conn));
        return false;
    }

    irc::log::print(_msg.get_raw());

    const std::vector<std::string>&   params = _msg.get_params();
    std::string user = params.front();
    std::string host = params.back();
    std::string realname = _msg.get_trailing();

    if (_conn.getuser().empty() == false) {
        _conn.send(irc::numerics::err_alreadyregistered_462(_conn));
    }

    _user = user;
    _host = host;
    _realname = realname;
    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::user::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::user(msg, conn));
}
