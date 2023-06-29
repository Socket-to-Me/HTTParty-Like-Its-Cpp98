#include "quit.hpp"


/* parametric constructor */
irc::quit::quit(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line("[quit] command received");
}

/* destructor */
irc::quit::~quit(void) {
    return;
}

/* execute command */
bool irc::quit::execute(void) {
    return false;
}

/* evaluate command */
bool irc::quit::evaluate(void) {
    return false;
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
