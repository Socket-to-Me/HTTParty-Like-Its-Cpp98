#include "join.hpp"

/* parametric constructor */
irc::join::join(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	std::cout << "join command created" << std::endl;
    return;
}

/* destructor */
irc::join::~join(void) {
    return;
}

/* execute command */
bool irc::join::execute(void) {

    if (irc::server::instance().isChannelExist(_channel) == false) { //new channel

        irc::server::instance().newChannel(_channel);
    }

    irc::channel&   channel = irc::server::instance().getchannel(_channel);

    if (channel.checkPassword(_password)) {

        channel.addUser(_conn);
        channel.addOperator(_conn);

        _conn.setchannelname(_channel);
        _conn.send(":" + _conn.getnick() + " JOIN :" + _channel + "\r\n");
        _conn.send(irc::numerics::rpl_topic_332(_conn));
        _conn.send(irc::numerics::rpl_namreply_353(_conn));
        _conn.send(irc::numerics::rpl_endofnames_366(_conn));
    }

    // Leave all channels
    if (_channel == "0") {
        // TODO
    }

    return true;
}

/* evaluate command */
bool irc::join::evaluate(void) {

    const std::vector<std::string>&     params = _msg.get_params();

    if (params.size() == 0) {
        _conn.settarget(_msg.get_command());
        _conn.send(irc::numerics::err_needmoreparams_461(_conn));
        return false;
    }

    std::string channel = params[0];

    if (channel[0] != '#') {
        _conn.settarget(channel);
        _conn.send(irc::numerics::err_badchanmask_476(_conn));
        return false;
    }

    // Check channel name correct
    
    _channel = channel;
    if (params.size() == 2) {
        _password = params[1];
    }
    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::join::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::join(msg, conn));
}
