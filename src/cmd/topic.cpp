#include "topic.hpp"

/* parametric constructor */
irc::topic::topic(const irc::msg& msg, irc::connection& conn)
: _msg(msg), _conn(conn) {
	irc::log::add_line("[topic] command received");
}

/* destructor */
irc::topic::~topic(void) {
    return;
}

/* execute command */
bool irc::topic::execute(void) {
    return false;
}

/* evaluate command */
bool irc::topic::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::topic::create(const irc::msg& msg, irc::connection& conn) {
    return irc::auto_ptr<irc::cmd>(new irc::topic(msg, conn));
}
