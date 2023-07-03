#include "quit.hpp"

// -- Q U I T -----------------------------------------------------------------


// -- public constructors -----------------------------------------------------

/* parametric constructor */
irc::quit::quit(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line(
			"["
			+ irc::color::green()
			+ "quit"
			+ irc::color::reset()
			+ "] command received from: "
			+ irc::color::blue()
			+ _conn.getnick()
			+ irc::color::reset());
	irc::log::print(msg.get_raw());
	return;
}

/* copy constructor */
irc::quit::quit(const quit& other)
: _msg(other._msg), _conn(other._conn) {}


/* destructor */
irc::quit::~quit(void) {
    return;
}


// -- public assignment operators ---------------------------------------------

/* copy assignment operator */
irc::quit& irc::quit::operator=(const quit& other) {
	// do nothing
	return *this;
}

/* execute command */
bool irc::quit::execute(void) {

	irc::server& serv = irc::server::instance();

	// add to remove queue
	serv.add_to_remove_queue(_conn);

    return true;
}

/* evaluate command */
bool irc::quit::evaluate(void) {
    return true;
}

/* send */
void irc::quit::send(irc::connection& conn) {

	irc::server& serv = irc::server::instance();

	// send quit message
	conn.send(":" + serv.getname()
			+ " QUIT :Server shutting down\r\n");
}

/* create command */
irc::auto_ptr<irc::cmd> irc::quit::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::quit(msg, conn));
}
