#include "part.hpp"

/* parametric constructor */
irc::part::part(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line(
			"["
			+ irc::color::green()
			+ "part"
			+ irc::color::reset()
			+ "] command received from: "
			+ irc::color::blue()
			+ _conn.getnick()
			+ irc::color::reset());
	irc::log::print(msg.get_raw());
    return;
}

/* destructor */
irc::part::~part(void) {
    return;
}

/* execute command */
bool irc::part::execute(void) {
    
	irc::channel&	channel = irc::server::instance().getchannel(_channel);

	channel.removeUser(_conn);

	if (_reason.empty()) {
		channel.broadcast(":" + _conn.getnick() + " PART " + _channel + "\r\n");
	
	} else {
		channel.broadcast(":" + _conn.getnick() + " PART " + _channel + " :" + _reason + "\r\n");
	}

	return true;
}

/* evaluate command */
bool irc::part::evaluate(void) {

    const std::vector<std::string> &params = _msg.get_params();

    if (_msg.have_params() == false)
    {
        _conn.settarget(_msg.get_command());
        _conn.send(irc::numerics::err_needmoreparams_461(_conn));
        return false;
    }

    std::string channel = params[0];

    if (irc::server::instance().isChannelExist(channel) == false)
    {
        _conn.settarget(channel);
        _conn.send(irc::numerics::err_nosuchchannel_403(_conn));
        return false;
    }

	if (irc::server::instance().getchannel(channel).isConnection(_conn) == false)
    {
        _conn.settarget(channel);
        _conn.send(irc::numerics::err_notonchannel_442(_conn));
        return false;
    }

    _channel = channel;
    if (params.size() == 2)
    {
        _reason = params[1];
    }
    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::part::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::part(msg, conn));
}
