#include "ping.hpp"

/* parametric constructor */
irc::ping::ping(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	std::cout << "ping command created" << std::endl;

	if (msg.get_params().size() != 1) {

		irc::out<2>::print("ping error: wrong number of parameters");

		return;
	}

	std::string param = "PONG " + msg.get_params()[0] + "\r\n";
	conn.send(param);
}

/* destructor */
irc::ping::~ping(void) {
    return;
}

/* execute command */
bool irc::ping::execute(void) {
    return false;
}

/* evaluate command */
bool irc::ping::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::ping::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::ping(msg, conn));
}
