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
			+ "] command received from: "
			+ irc::color::blue()
			+ _conn.getnick()
			+ irc::color::reset());
	irc::log::print(msg.get_raw());
	return;
}

/* destructor */
irc::pass::~pass(void) {}


// -- public overloaded methods -----------------------------------------------

/* execute command */
bool irc::pass::execute(void) {
	// set password
	//_conn.setpassword(_msg.get_params()[0]);
	// set registered
	_conn.register_client();
	_conn.validate_pass();
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
	if (_msg.have_params() == false) {
		// send error message
		_conn.settarget(_msg.get_command());
		_conn.send(irc::numerics::err_needmoreparams_461(_conn));
		return false;
	}

	irc::server& serv = irc::server::instance();

	const std::string& pass = serv.get_password();

	// check wrong password
	if (pass != _msg.get_params()[0]) {
		return false;
	}

    return true;
}


// -- public static methods ---------------------------------------------------

/* create command */
irc::auto_ptr<irc::cmd> irc::pass::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::pass(msg, conn));
}
