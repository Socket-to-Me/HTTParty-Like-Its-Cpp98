#include "kick.hpp"


/* parametric constructor */
irc::kick::kick(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line(
			"["
			+ irc::color::green()
			+ "kick"
			+ irc::color::reset()
			+ "] command received from: "
			+ irc::color::blue()
			+ _conn.getnick()
			+ irc::color::reset());
	irc::log::print(msg.get_raw());
    return;
}

/* destructor */
irc::kick::~kick(void) {
    return;
}

/* execute command */
bool irc::kick::execute(void) {

    irc::channel&       chan = irc::server::instance().getchannel(_channel);
    irc::connection&    usr = irc::server::instance().getconnection(_user);
    
    chan.removeUser(usr);

    if (_comment.empty()) { // --- kick without comment
        user.send(":" + _conn.getnick() + " KICK " + _channel + " " + _user + "\r\n");

    } else { // ------------------ kick with comment
        user.send(":" + _conn.getnick() + " KICK " + _channel + " " + _user + " " + _comment + "\r\n");
    }

    return true;
}

/* evaluate command */
bool irc::kick::evaluate(void) {

    const std::vector<std::string>&     params = _msg.get_params();

    if (params.size() < 2) {
        _conn.settarget(_msg.get_command());
        _conn.send(irc::numerics::err_needmoreparams_461(_conn));
        return false;
    }

    std::string channel = params[0];
    if (irc::server::instance().isChannelExist(channel) == false) {
        _conn.settarget(channel);
        _conn.send(irc::numerics::err_nosuchchannel_403(_conn));
        return false;
    }

    std::string user = params[1];
    if (irc::server::instance().isNickInUse(user) == false) {
        _conn.settarget(user);
        _conn.send(irc::numerics::err_nosuchnick_401(_conn));
        return false;
    }

    irc::channel&       chan = irc::server::instance().getchannel(_channel);
    irc::connection&    usr = irc::server::instance().getconnection(_user);

    if (chan.isConnection(usr) == false) {
        _conn.settarget(user);
        _conn.setchannelname(channel);
        _conn.send(irc::numerics::err_usernotinchannel_441(_conn));
        return false;
    }

    if (chan.isConnection(_conn) == false) {
        _conn.settarget(channel);
        _conn.send(irc::numerics::err_notonchannel_442(_conn));
        return false;
    }

    if (chan.isOperator(_conn) == false) {
        _conn.settarget(channel);
        _conn.send(irc::numerics::err_chanoprivsneeded_482(_conn));
        return false;
    }

    _channel = channel;
    _user = user;

    if (_msg.have_trailing()) {
        _comment = _msg.get_trailing();
    }

    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::kick::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::kick(msg, conn));
}
