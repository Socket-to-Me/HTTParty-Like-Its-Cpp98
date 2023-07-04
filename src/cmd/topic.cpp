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
	irc::log::print(msg.get_raw());
    return;
}

/* destructor */
irc::topic::~topic(void) {
    return;
}

/* execute command */
bool irc::topic::execute(void) {

    irc::channel& chan = irc::server::instance().getchannel(_channel);

    if (_topic.empty()) { // --- view topic

        _conn.setchannelname(_channel);

        if (chan.gettopic().empty()) {
            _conn.send(irc::numerics::rpl_notopic_331(_conn));

        } else {
            _conn.send(irc::numerics::rpl_topic_332(_conn));
        }

    } else { // ---------------- edit topic

        chan.broadcast(":" + _conn.getnick() + " TOPIC " + _channel + " " + _topic + "\r\n");
    }

    return true;
}

/* evaluate command */
bool irc::topic::evaluate(void) {
    
    const std::vector<std::string>&     params = _msg.get_params();

    if (params.size() < 1) {
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

    _channel = channel;

    if (_msg.have_trailing()) {

        _topic = _msg.get_trailing();

    }

    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::topic::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::topic(msg, conn));
}
