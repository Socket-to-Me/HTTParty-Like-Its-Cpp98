#include "pass.hpp"

// -- C O N S T R U C T O R S -------------------------------------


/* parametric constructor */
irc::pass::pass(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	std::cout << "pass command created" << std::endl;
	return;
}

/* destructor */
irc::pass::~pass(void) {
    return;
}

// -- V I R T U A L  M E T H O D S --------------------------------

/* execute command */
bool irc::pass::execute(void) {

    // _conn.setpassword(_password);
    return true;
}

/* evaluate command */
bool irc::pass::evaluate(void) {

    // if (irc::server::isConnRegistered(_conn)) {
    //     _conn.send(irc::numerics::err_alreadyregistered_462(_conn));
    //     return false;
    // }

    // std::vector<irc::token>& params = _data.getparams();

    // if (params.size() == 0) {
    //     conn.send(irc::numerics::err_needmoreparams_461(conn));
    //     return false;
    // }
    // else if (params.size() != 1) {
    //     return false;
    // }

    // _password = params[0].getstr();
    return true;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::pass::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::pass(msg, conn));
}
