#include "ping.hpp"

/* parametric constructor */
irc::ping::ping(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	std::cout << "ping command created" << std::endl;

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
	// check there is only one parameter
	return (_msg.get_params().size() == 1);
}

/* create command */
irc::auto_ptr<irc::cmd> irc::ping::create(const irc::msg& msg, irc::connection& conn) {
	// create ping command
    return irc::auto_ptr<irc::cmd>(new irc::ping(msg, conn));
}
