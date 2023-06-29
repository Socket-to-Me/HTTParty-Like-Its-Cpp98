#include "privmsg.hpp"


/* parametric constructor */
irc::privmsg::privmsg(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line("[privmsg] command received");
}

/* destructor */
irc::privmsg::~privmsg(void) {
    return;
}

/* execute command */
bool irc::privmsg::execute(void) {

    if (_ischannel) {

        irc::channel&   channel = irc::server::instance().getchannel(_target);
        channel.broadcast(":" + _conn.getnick() + " PRIVMSG " + _target + " " + _str + "\r\n");
    }
    else {

        irc::server::instance().getconnection(_target).send(":" + _conn.getnick() + " PRIVMSG " + _target + " " + _str + "\r\n");
    }

    return true;
}

/* evaluate command */
bool irc::privmsg::evaluate(void) {
    
    if (!_msg.have_params()) {
        _conn.settarget(_msg.get_command());
        _conn.send(irc::numerics::err_needmoreparams_461(_conn));
        return false;
    }

    const std::vector<std::string>&     params = _msg.get_params();
    std::string target = params[0];
    std::string str = params.back();
    
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
