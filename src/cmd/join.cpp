#include "join.hpp"

/* default constructor */
irc::join::join(void) {
	return;
}

/* destructor */
irc::join::~join(void) {
	return;
}

/* execute command */
bool irc::join::execute(void) {
	return false;
}

/* evaluate command */
bool irc::join::evaluate(void) {
	return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::join::create(void) {
	return irc::auto_ptr<irc::cmd>(new irc::join());
}
