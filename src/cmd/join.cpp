#include "join.hpp"

/* parametric constructor */
irc::join::join(const irc::msg &msg, irc::connection &conn)
    : _msg(msg), _conn(conn)
{
    irc::log::add_line(
        "[" + irc::color::green() + "join" + irc::color::reset() + "] command received from: " + irc::color::blue() + _conn.getnick() + irc::color::reset());
    irc::log::print(msg.get_raw());
    return;
}

/* destructor */
irc::join::~join(void)
{
    return;
}

/* execute command */
bool irc::join::execute(void)
{
    // Leave all channels
    if (_channel == "0") {
        irc::server::instance().leave_all_channels(_conn);
        return true;
    }

    // Join a channel
    if (irc::server::instance().isChannelExist(_channel) == false)
    { // ---------------------------------------------------------------- new channel

        irc::server::instance().newChannel(_channel);
        irc::channel& channel = irc::server::instance().getchannel(_channel);

        channel.addUser(_conn);
        channel.addOperator(_conn);

        if (_password.empty() == false) { // -------- set password

            channel.set_mode_channel_key(true);
            channel.setkey(_conn, _password);
        }

        // replies
        channel.broadcast(":" + _conn.getnick() + "!" + _conn.getuser() + "@" + _conn.gethost() + " JOIN :" + _channel + "\r\n");

    } else { // ---------------------------------------------------- existing channel

        irc::channel& channel = irc::server::instance().getchannel(_channel);

        // check not in channel already
        if (channel.isConnection(_conn) == true) {
            _conn.settarget(_conn.getnick());
            _conn.setchannelname(_channel);
            _conn.send(irc::numerics::err_useronchannel_443(_conn));
            return false;
        }

        if (channel.is_mode_channel_key()) { // --------------------- private channel
            if (channel.checkPassword(_password) == false) {

                // ------------------ incorrect password
                _conn.settarget(_channel);
                _conn.send(irc::numerics::err_badchannelkey_475(_conn));
                return false;
            }
        }

        if (channel.is_mode_invite_only()) { // ----------------- invite-only channel
            if (channel.isInvited(_conn) == false) { 

            // ---------------------- not invited
                _conn.settarget(_channel);
                _conn.send(irc::numerics::err_inviteonlychan_473(_conn));
                return false;
            }
        }

        if (channel.is_mode_user_limit()) { // ------------------- user limit channel
            if (channel.getconnections().size() >= channel.getlimit()) {

                // ------------------ channel full
                _conn.settarget(_channel);
                _conn.send(irc::numerics::err_channelisfull_471(_conn));
                return false;
            }
        }

        // success
        channel.addUser(_conn);

        // replies
        channel.broadcast(":" + _conn.getnick() + "!" + _conn.getuser() + "@" + _conn.gethost() + " JOIN :" + _channel + "\r\n");
        _conn.setchannelname(_channel);
        if (channel.gettopic().empty()) {
            _conn.send(irc::numerics::rpl_notopic_331(_conn));
        } else {
            _conn.send(irc::numerics::rpl_topic_332(_conn));
        }
    }

    // replies
    irc::channel& channel = irc::server::instance().getchannel(_channel);
    _conn.setchannelname(_channel);
    _conn.send(irc::numerics::rpl_namreply_353(_conn));
    _conn.send(irc::numerics::rpl_endofnames_366(_conn));

    return true;
}

/* evaluate command */
bool irc::join::evaluate(void)
{
    if (_msg.have_params() == false) {
        _conn.settarget(_msg.get_command());
        _conn.send(irc::numerics::err_needmoreparams_461(_conn));
        return false;
    }

    const std::vector<std::string> &params = _msg.get_params();
    std::string channel = params[0];

    if (irc::server::instance().isChannelNameValid(channel) == false) {
        _conn.settarget(channel);
        _conn.send(irc::numerics::err_badchanmask_476(_conn));
        return false;
    }

    _channel = channel;
    if (params.size() > 1) {
        _password = params[1];
    }

    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::join::create(const irc::msg &msg, irc::connection &conn)
{
    return irc::auto_ptr<irc::cmd>(new irc::join(msg, conn));
}
