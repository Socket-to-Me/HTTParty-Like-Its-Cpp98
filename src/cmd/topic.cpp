#include "topic.hpp"

/* parametric constructor */
irc::topic::topic(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line(
			"["
			+ irc::color::green()
			+ "topic"
			+ irc::color::reset()
			+ "] command received from: "
			+ irc::color::blue()
			+ _conn.getnick()
			+ irc::color::reset());
    return;
}

/* destructor */
irc::topic::~topic(void) {
    return;
}

/* execute command */
bool irc::topic::execute(void) {
    return false;
}

/* evaluate command */
bool irc::topic::evaluate(void) {
    
    if (_msg.have_params() == false) {
        return false;
    }

    const std::vector<std::string>& params = _msg.get_params();

    std::string channel = params[0];
    if (irc::server::instance().isChannelExist(channel) == false) {
        _conn.settarget(channel);
        _conn.send(irc::numerics::err_nosuchchannel_403(_conn));
        return false;
    }

    // irc::channel& chan = irc::server::instance().getchannel(channel);
    // if (chan.is) {
    //     _conn.settarget(channel);
    //     _conn.send(irc::numerics::err_nosuchchannel_403(_conn));
    //     return false;
    // }

    _channel = channel;
    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::topic::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::topic(msg, conn));
}
