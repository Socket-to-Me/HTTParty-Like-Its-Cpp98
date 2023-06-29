#include "pass.hpp"


// -- P A S S -----------------------------------------------------------------


// -- public constructors -----------------------------------------------------

/* parametric constructor */
irc::pass::pass(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line(
			"["
			+ irc::color::green()
			+ "pass"
			+ irc::color::reset()
			+ "] command received");
}

/* destructor */
irc::pass::~pass(void) {}


// -- public overloaded methods -----------------------------------------------

/* execute command */
bool irc::pass::execute(void) {
	// set password
	_conn.setpassword(_msg.get_params()[0]);
	// set registered
	_conn.register_client();
    return true;
}

/* evaluate command */
bool irc::pass::evaluate(void) {

	// check client is already registered
     if (_conn.is_registered()) {
		 // send error message
         _conn.send(irc::numerics::err_alreadyregistered_462(_conn));
         return false;
     }

	// check for invalid number of parameters
	if (_msg.get_params().size() != 1) {
		// send error message
		_conn.send(irc::numerics::err_needmoreparams_461(_conn));
		return false;
	}
    return true;
}


// -- public static methods ---------------------------------------------------

/* create command */
irc::auto_ptr<irc::cmd> irc::pass::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::pass(msg, conn));
}
