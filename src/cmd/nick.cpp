#include "nick.hpp"


/* parametric constructor */
irc::nick::nick(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	std::cout << "nick command created" << std::endl;
	return;
}

/* destructor */
irc::nick::~nick(void) {
    return;
}

/* execute command */
bool irc::nick::execute(void) {

    // _conn.setnick(_nick);
    return true;
}

/* evaluate command */
bool irc::nick::evaluate(void) {

    // std::vector<irc::token>& params = _data.getparams();

    // if (params.size() == 0) {
    //     _conn.send(irc::numerics::err_nonicknamegiven_431(conn));
    //     return false;
    // }
    // else if (params.size() != 1) {
    //     return false;
    // }

    // std::string nick = params[0].getstr();

    // if (!isValidNick(nick)) {
    //     _conn.send(irc::numerics::err_erroneusnickname_432(conn));
    //     return false;
    // }
    // else if (irc::server::isNickInUse(nick)) {
    //     _conn.send(irc::numerics::err_nicknameinuse_433(_conn));
    //     return false;
    // }

    // _nick = nick;
    return true;
}

bool	irc::nick::isValidNick(const std::string& nick) const {

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
