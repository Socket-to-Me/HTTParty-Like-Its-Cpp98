#include "cmd_factory.hpp"


/* instance */
IRC::cmd_factory IRC::cmd_factory::_instance;


/* default constructor */
IRC::cmd_factory::cmd_factory(void) {
	_cmds["JOIN"] = &IRC::join::create;
	return;
}

/* copy constructor */
IRC::cmd_factory::cmd_factory(const cmd_factory&) {
	return;
}

/* destructor */
IRC::cmd_factory::~cmd_factory(void) {
	return;
}

/* copy assignment operator */
IRC::cmd_factory& IRC::cmd_factory::operator=(const cmd_factory&) {
	return *this;
}


// -- F A C T O R Y  M E T H O D S --------------------------------------------

/* create command */
IRC::cmd_factory::cmd_ptr IRC::cmd_factory::search(const std::string& cmd) {
	if (cmd == "JOIN") {
		cmd_ptr join = IRC::join::create();
		return join;
	}
	return cmd_ptr();
}

/* get instance */
IRC::cmd_factory& IRC::cmd_factory::instance(void) {
	return IRC::cmd_factory::_instance;
}

