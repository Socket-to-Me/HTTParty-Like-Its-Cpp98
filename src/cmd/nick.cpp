#include "nick.hpp"


/* parametric constructor */
irc::nick::nick(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line(
			"["
			+ irc::color::green()
			+ "nick"
			+ irc::color::reset()
			+ "] command received from: "
			+ irc::color::blue()
			+ _conn.getnick()
			+ irc::color::reset());
	irc::log::print(msg.get_raw());
    return;
}

/* destructor */
irc::nick::~nick(void) {
    return;
}

/* execute command */
bool irc::nick::execute(void) {

    irc::server&    serv = irc::server::instance();

    _conn.setnick(_nick);
    serv.broadcast(":" + _conn.getnick() + "!" + _conn.getuser() + "@" + _conn.gethost() + " NICK " + _nick + "\r\n");
	_conn.validate_nick();
    return true;
}

/* evaluate command */
bool irc::nick::evaluate(void) {

    if (_msg.have_params() == false) {
        _conn.send(irc::numerics::err_nonicknamegiven_431(_conn));
        return false;
    }

    const std::vector<std::string>& params = _msg.get_params();
    if (params.size() != 1) {
        return false;
    }

    std::string nick = params[0];

    if (isValidNick(nick) == false) {
        _conn.settarget(nick);
        _conn.send(irc::numerics::err_erroneusnickname_432(_conn));
        return false;
    }

    if (irc::server::instance().isNickInUse(nick)) {
        _conn.setnick(nick);
        _conn.duplicate_nick();
        _conn.settarget(nick);
        _conn.send(irc::numerics::err_nicknameinuse_433(_conn));
        return false;
    }

    _nick = nick;
    return true;
}

bool	irc::nick::isValidNick(const std::string& nick) const {

    // less than 15 characters
    if (nick.length() > 15) {
        return false;
    }

    // no leading character (# & :)
    if (nick.find("#") == 0 || nick.find("&") == 0 || nick.find(":") == 0) {
        return false;
    }

    // no ascii space (# & :)
    if (nick.find(" ") != std::string::npos) {
        return false;
    }

    // is printable
    for (size_t i=0; i<nick.length(); ++i) {
        if (!isprint(nick[i]))
            return false;
   }

    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::nick::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::nick(msg, conn));
}
