#include "cmd_factory.hpp"


/* instance */
irc::cmd_factory irc::cmd_factory::_instance;


/* default constructor */
irc::cmd_factory::cmd_factory(void) {
	_cmds["JOIN"] = &irc::join::create;
	return;
}

/* copy constructor */
irc::cmd_factory::cmd_factory(const cmd_factory&) {
	return;
}

/* destructor */
irc::cmd_factory::~cmd_factory(void) {
	return;
}

/* copy assignment operator */
irc::cmd_factory& irc::cmd_factory::operator=(const cmd_factory&) {
	return *this;
}


// -- F A C T O R Y  M E T H O D S --------------------------------------------

/* create command */
irc::cmd_factory::cmd_ptr irc::cmd_factory::search(const std::string& cmd) {
	if (cmd == "JOIN") {
		cmd_ptr join = irc::join::create();
		return join;
	}
	return cmd_ptr();
}

/* get instance */
irc::cmd_factory& irc::cmd_factory::instance(void) {
	return irc::cmd_factory::_instance;
}

