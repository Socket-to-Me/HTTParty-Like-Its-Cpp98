#include "invite.hpp"

/* parametric constructor */
irc::invite::invite(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line(
			"["
			+ irc::color::green()
			+ "invite"
			+ irc::color::reset()
			+ "] command received from: "
			+ irc::color::blue()
			+ _conn.getnick()
			+ irc::color::reset());
	irc::log::print(msg.get_raw());
    return;
}

/* destructor */
irc::invite::~invite(void) {
    return;
}

/* execute command */
bool irc::invite::execute(void) {

    irc::channel& chan = irc::server::instance().getchannel(_channel);
    irc::connection& usr = irc::server::instance().getconnection(_nick);

	chan.addInvitation(usr);

    _conn.send(irc::numerics::rpl_inviting_341(_conn));
    usr.send(":" + _conn.getnick() + "!" + _conn.getuser() + "@" + _conn.gethost() + " INVITE " + _nick + " " + _channel + "\r\n");

    return true;
}

/* evaluate command */
bool irc::invite::evaluate(void) {

    const std::vector<std::string>&     params = _msg.get_params();

    if (params.size() < 2) {
        _conn.settarget(_msg.get_command());
        _conn.send(irc::numerics::err_needmoreparams_461(_conn));
        return false;
    }

    std::string nick = params[0];
    if (irc::server::instance().isNickInUse(nick) == false) {
        _conn.settarget(nick);
        _conn.send(irc::numerics::err_nosuchnick_401(_conn));
        return false;
    }

    std::string channel = params[1];
    if (irc::server::instance().isChannelExist(channel) == false) {
        _conn.settarget(channel);
        _conn.send(irc::numerics::err_nosuchchannel_403(_conn));
        return false;
    }

    irc::channel& chan = irc::server::instance().getchannel(channel);
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

    irc::connection& usr = irc::server::instance().getconnection(nick);

    if (chan.isConnection(usr) == true) {
        _conn.settarget(nick);
        _conn.setchannelname(channel);
        _conn.send(irc::numerics::err_useronchannel_443(_conn));
        return false;
    }

    _channel = channel;
    _nick = nick;

    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::invite::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::invite(msg, conn));
}
