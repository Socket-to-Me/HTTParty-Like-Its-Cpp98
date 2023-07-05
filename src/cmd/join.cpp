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

	std::cout << "EXECUTE JOIN" << std::endl;

    // Leave all channels
    if (_channel == "#0") {
        irc::server::instance().leave_all_channels(_conn);
    }

    // Join a channel
    if (irc::server::instance().isChannelExist(_channel) == false)
    { // ------------------------------------------------------ new channel

        irc::server::instance().newChannel(_channel);
        irc::channel& channel = irc::server::instance().getchannel(_channel);

        channel.addUser(_conn);
        channel.addOperator(_conn);

        if (!_password.empty()) { // --- set password

            channel.set_mode_channel_key(true);
            channel.setkey(_conn, _password);
        }

    } else { // ----------------------------------------------- existing channel

        irc::channel& channel = irc::server::instance().getchannel(_channel);

        if (channel.is_mode_channel_key())
        { // ---------------------------------------- private channel

            if (channel.checkPassword(_password)) {

                channel.addUser(_conn);

            } else { // -------------- wrong password

                _conn.settarget(_channel);
                _conn.send(irc::numerics::err_badchannelkey_475(_conn));
                return false;
            }

        } else { // --------------------------------- public channel

            channel.addUser(_conn);
        }

        channel.broadcast(":" + _conn.getnick() + " JOIN :" + _channel + "\r\n");
    }

    // replies
    _conn.setchannelname(_channel);
    _conn.send(irc::numerics::rpl_topic_332(_conn));
    _conn.send(irc::numerics::rpl_namreply_353(_conn));
    _conn.send(irc::numerics::rpl_endofnames_366(_conn));

	std::cout << "EXECUTE JOIN END" << std::endl;

    return true;
}

/* evaluate command */
bool irc::join::evaluate(void)
{

	std::cout << "EVALUATE JOIN" << std::endl;

    const std::vector<std::string> &params = _msg.get_params();

    if (params.size() == 0)
    {
        _conn.settarget(_msg.get_command());
        _conn.send(irc::numerics::err_needmoreparams_461(_conn));
        return false;
    }

    std::string channel = params[0];

    if (irc::server::instance().isChannelNameValid(channel) == false)
    {
        _conn.settarget(channel);
        _conn.send(irc::numerics::err_badchanmask_476(_conn));
        return false;
    }

    _channel = channel;
    if (params.size() == 2)
    {
        _password = params[1];
    }


	std::cout << "EVALUATE JOIN END" << std::endl;

    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::join::create(const irc::msg &msg, irc::connection &conn)
{
    return irc::auto_ptr<irc::cmd>(new irc::join(msg, conn));
}
