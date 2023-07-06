#include "who.hpp"

/* parametric constructor */
irc::who::who(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line(
			"["
			+ irc::color::green()
			+ "who"
			+ irc::color::reset()
			+ "] command received from: "
			+ irc::color::blue()
			+ _conn.getnick()
			+ irc::color::reset());
	irc::log::print(msg.get_raw());
    return;
}

/* destructor */
irc::who::~who(void) {
    return;
}

/* execute command */
bool irc::who::execute(void) {

    const std::vector<std::string>& params = _msg.get_params();

    if (_ischannel) { // ---------------------- channel

        irc::channel&                           channel = irc::server::instance().getchannel(_target);
        const std::vector<irc::connection*>&    connections = channel.getconnections();

        std::vector<irc::connection*>::const_iterator   it;

        for (it = connections.begin(); it != connections.end(); ++it) {

            std::string nick = (*it)->getnick();
            _conn.settarget(nick);
            _conn.setchannelname(_target);
            _conn.send(irc::numerics::rpl_whoreply_352(_conn));
        }

        _conn.settarget(_target);
        _conn.send(irc::numerics::rpl_endofwho_315(_conn));

    } else { // --------------------------------- user

        _conn.settarget(_target);
        _conn.setchannelname("*");
        _conn.send(irc::numerics::rpl_whoreply_352(_conn));
        _conn.send(irc::numerics::rpl_endofwho_315(_conn));
    }

    return true;
}

/* evaluate command */
bool irc::who::evaluate(void) {

    if (_msg.have_params() == false)
    {
        _conn.settarget(_msg.get_command());
        _conn.send(irc::numerics::err_needmoreparams_461(_conn));
        return false;
    }

    const std::vector<std::string>& params = _msg.get_params();

    std::string target = params[0];

    if (target[0] == '#') { //----------------- channel

        if (irc::server::instance().isChannelExist(target) == false) {
            _conn.settarget(target);
            _conn.send(irc::numerics::err_nosuchchannel_403(_conn));
            return false;
        }

        _ischannel = true;
    }
    else { // --------------------------------- user

        if (irc::server::instance().isNickInUse(target) == false) {
            _conn.settarget(target);
            _conn.send(irc::numerics::err_nosuchnick_401(_conn));
            return false;
        }

        _ischannel = false;
    }

    _target = target;

    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::who::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::who(msg, conn));
}
