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

    return false;
}

/* evaluate command */
bool irc::join::evaluate(void) {

    // std::vector<irc::token>& params = _data.getparams();

    // if (params.size() == 0) {
    //     _conn.send(irc::numerics::err_needmoreparams_461(conn));
    //     return false;
    // }
    // else if (params.size() > 2) {
    //     return false;
    // }

    // std::string channel = params[0];
    // if (params.size() == 2) {
    //     std::string password = params[1];
    // }

    // if (!irc::server::isChannelExist(channel)) {
    //     return false;
    // }

    // const std::vector<irc::channel>&    channels = irc::server::getchannels();

    // for (std::vector<irc::channel>::const_iterator it=channels.begin(); it!=channels.end()); ++it) {
    //     if (channel == it) {
    //         return true;
    //     }
    // }


    // // Leave all channels
    // if (channel == "0") {
    // if (channel[0] != '#') {
    //     _conn.send(irc::numerics::err_badchanmask_476(conn));
    //     return false;
    // }

    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::join::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::join(msg, conn));
}
