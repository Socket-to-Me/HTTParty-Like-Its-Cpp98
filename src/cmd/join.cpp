#include "join.hpp"

/* default constructor */
IRC::join::join(void) {
	return;
}

/* destructor */
IRC::join::~join(void) {
	return;
}

/* execute command */
bool IRC::join::execute(void) {
	return false;
}

/* evaluate command */
bool IRC::join::evaluate(void) {
	return false;
}

/* create command */
IRC::auto_ptr<IRC::cmd> IRC::join::create(void) {
	return IRC::auto_ptr<IRC::cmd>(new IRC::join());
}
