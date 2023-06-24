#include "nick.hpp"

/* default constructor */
irc::nick::nick(void) {
    return;
}

/* parametric constructor */
// irc::nick::nick(const std::data& data)
// : _data(data), _conn(data.getconn()) {
//     return;
// }

/* destructor */
irc::nick::~nick(void) {
    return;
}

/* execute command */
bool irc::nick::execute(void) {
    return false;
}

/* evaluate command */
bool irc::nick::evaluate(void) {

    // if (irc::server::isNickInUse(_nick)) {
    //     _conn.send(irc::numerics::err_nicknameinuse_433(_conn));
    //     return false;
    // }

    // std::vector<irc::token>& params = _data.getparams();

    // if (params.size() == 0) {
    //     conn.send(irc::numerics::err_nonicknamegiven_431(conn));
    //     return false;
    // }
    // else if (params.size() != 1) {
    //     return false;
    // }

    // do nick checks with errors - https://dd.ircdocs.horse/refs/commands/nick

    // _nick = params[0].getstr();
    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::nick::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::nick());
}
