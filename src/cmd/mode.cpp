#include "mode.hpp"

/* parametric constructor */
irc::mode::mode(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line(
			"["
			+ irc::color::green()
			+ "mode"
			+ irc::color::reset()
			+ "] command received from: "
			+ irc::color::blue()
			+ _conn.getnick()
			+ irc::color::reset());
    return;
}

/* destructor */
irc::mode::~mode(void) {
    return;
}

/* execute command */
bool irc::mode::execute(void) {

    const std::vector<std::string>& params = _msg.get_params();

    if (_ischannel) { //target is a channel

        _conn.setchannelname(_target);
        irc::channel&   channel = irc::server::instance().getchannel(_target);

        if (params.size() == 1) {
            _conn.send(irc::numerics::rpl_channelmodeis_324(_conn));
        }
        else {
            std::string modestring = params[1];
            channel.setmode(_conn, modestring);
            _conn.send(":" + irc::server::instance().getname() + " MODE " + _target + " " + modestring + "\r\n");
        }
    }
    else { //target is a nickname

        if (params.size() == 1) {
            _conn.send(irc::numerics::rpl_umodeis_221(_conn));
        }
        // no modes for users
    }

    return true;
}

/* evaluate command */
bool irc::mode::evaluate(void) {

    if (_msg.have_params() == false) {
        _conn.send(irc::numerics::err_nonicknamegiven_431(_conn));
        return false;
    }

    const std::vector<std::string>& params = _msg.get_params();
    std::string target = params[0];

    if (target[0] == '#') { //target is a channel

        if (irc::server::instance().isChannelExist(target) == false) {
            _conn.send(irc::numerics::err_nosuchchannel_403(_conn));
            return false;
        }

        _ischannel = true;
    }
    else { //target is a nickname

        if (irc::server::instance().isNickInUse(target) == false) {
            _conn.send(irc::numerics::err_nosuchnick_401(_conn));
            return false;
        }
        else if (_conn.getnick() != target) {
            _conn.send(irc::numerics::err_usersdontmatch_502(_conn));
            return false;
        }

        _ischannel = false;
    }

    _target = target;
    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::mode::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::mode(msg, conn));
}
