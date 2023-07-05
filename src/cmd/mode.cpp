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
	irc::log::print(msg.get_raw());
    return;
}

/* destructor */
irc::mode::~mode(void) {
    return;
}

/* execute command */
bool irc::mode::execute(void) {

    const std::vector<std::string>& params = _msg.get_params();

    if (_ischannel) { // ---------------------- channel mode

        if (params.size() == 1) { // --- current modes
            _conn.setchannelname(_target);
            _conn.send(irc::numerics::rpl_channelmodeis_324(_conn));

        } else { // -------------------- change modes
            irc::channel&   channel = irc::server::instance().getchannel(_target);
            channel.setmode(_conn, params);
            _conn.send(":" + _conn.getnick() + " MODE " + _target + " " + params[1] + "\r\n");
        }
    }
    else { // --------------------------------- user mode

        if (params.size() == 1) { // --- current modes
            _conn.send(irc::numerics::rpl_umodeis_221(_conn));

        } else { // -------------------- no modes for users
            _conn.settarget(params[1]);
            _conn.send(irc::numerics::err_unknownmode_472(_conn));
        }
    }

    return true;
}

/* evaluate command */
bool irc::mode::evaluate(void) {

    const std::vector<std::string>& params = _msg.get_params();

    if (params.size() == 0)
    {
        _conn.settarget(_msg.get_command());
        _conn.send(irc::numerics::err_needmoreparams_461(_conn));
        return false;
    }

    std::string target = params[0];

    if (target[0] == '#') { //----------------- channel mode

        if (irc::server::instance().isChannelExist(target) == false) {
            _conn.send(irc::numerics::err_nosuchchannel_403(_conn));
            return false;
        }

        if (params.size() > 1) {
            
            irc::channel&   channel = irc::server::instance().getchannel(_target);

            if (channel.check_modestring(params[1]) == false) {
                _conn.settarget(params[1]);
                _conn.send(irc::numerics::err_unknownmode_472(_conn));
                return false;
            }

        }

        _ischannel = true;
    }
    else { // --------------------------------- user mode

        if (irc::server::instance().isNickInUse(target) == false) {
            _conn.settarget(target);
            _conn.send(irc::numerics::err_nosuchnick_401(_conn));
            return false;
        }
        
        if (_conn.getnick() != target) {
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
