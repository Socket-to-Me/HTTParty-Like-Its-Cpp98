#include "ping.hpp"

/* parametric constructor */
irc::ping::ping(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	 irc::log::add_line(
	 		"["
	 		+ irc::color::green()
	 		+ "ping"
	 		+ irc::color::reset()
	 		+ "] command received from: "
	 		+ irc::color::blue()
	 		+ _conn.getnick()
	 		+ irc::color::reset());
	 //irc::log::print(msg.get_raw());
	return;
}

/* destructor */
irc::ping::~ping(void) {
    return;
}

/* execute command */
bool irc::ping::execute(void) {
	std::string param = "PONG " + _msg.get_params()[0] + "\r\n";
	_conn.send(param);
    return true;
}

/* evaluate command */
bool irc::ping::evaluate(void) {
	return true;
	// check there is only one parameter
	return (_msg.get_params().size() == 1);
}

void irc::ping::send(irc::connection& conn) {

	irc::server& serv = irc::server::instance();

	// send quit message
	conn.send("PING :" + serv.getname() + "\r\n");

}

/* create command */
irc::auto_ptr<irc::cmd> irc::ping::create(const irc::msg& msg, irc::connection& conn) {
	// create ping command
    return irc::auto_ptr<irc::cmd>(new irc::ping(msg, conn));
}
