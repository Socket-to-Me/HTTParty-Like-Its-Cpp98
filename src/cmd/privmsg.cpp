#include "privmsg.hpp"


/* parametric constructor */
irc::privmsg::privmsg(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line(
			"["
			+ irc::color::green()
			+ "privmsg"
			+ irc::color::reset()
			+ "] command received from: "
			+ irc::color::blue()
			+ _conn.getnick()
			+ irc::color::reset());
	irc::log::print(msg.get_raw());
    return;
}

/* destructor */
irc::privmsg::~privmsg(void) {
    return;
}

/* execute command */
bool irc::privmsg::execute(void) {

    if (_ischannel) {

        irc::channel&   channel = irc::server::instance().getchannel(_target);
        if (channel.broadcastExcept(":" + _conn.getnick() + "!" + _conn.getuser() + "@" + _conn.gethost() + " PRIVMSG " + _target + " " + _str + "\r\n", _conn) == false) {
            _conn.settarget(_target);
            _conn.send(irc::numerics::err_cannotsendtochan_404(_conn));
            return false;
        }
    }
    else {

        irc::connection&    user = irc::server::instance().getconnection(_target);
        user.send(":" + _conn.getnick() + "!" + _conn.getuser() + "@" + _conn.gethost() + " PRIVMSG " + _target + " " + _str + "\r\n");
    }

    return true;
}

/* evaluate command */
bool irc::privmsg::evaluate(void) {

    if (_msg.have_params() == false || _msg.have_trailing() == false) {
        _conn.settarget(_msg.get_command());
        _conn.send(irc::numerics::err_needmoreparams_461(_conn));
        return false;
    }

    const std::vector<std::string>&     params = _msg.get_params();
    std::string                         target = params.front();
    std::string                         str = _msg.get_trailing();

    if (target[0] == '#') { // --- target is a channel

        if (irc::server::instance().isChannelExist(target) == false) {
            _conn.settarget(target);
            _conn.send(irc::numerics::err_nosuchchannel_403(_conn));
            return false;
        }

        _ischannel = true;
    }
    else { // -------------------- target is a nickname

        if (irc::server::instance().isNickInUse(target) == false) {
            _conn.settarget(target);
            _conn.send(irc::numerics::err_nosuchnick_401(_conn));
            return false;
        }

        _ischannel = false;
    }

    _target = target;
    _str = str;

    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::privmsg::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::privmsg(msg, conn));
}
