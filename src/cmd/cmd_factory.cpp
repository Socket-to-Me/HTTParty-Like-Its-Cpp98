#include "cmd_factory.hpp"

std::map<std::string, irc::cmd_factory::cmd_maker>	init(void) {

	std::map<std::string, irc::cmd_factory::cmd_maker> _cmds;

	std::pair<std::string, irc::cmd_factory::cmd_maker> _pair("INVITE", &irc::invite::create);

	_cmds.insert(_pair);

	// _cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>{"INVITE", irc::invite::create});
	// _cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("JOIN", irc::join::create));
	// _cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("KICK", irc::kick::create));
	// _cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("LIST", irc::list::create));
	// _cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("MODE", irc::mode::create));
	// _cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("NICK", irc::nick::create));
	// _cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("PART", irc::part::create));
	// _cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("PASS", irc::pass::create));
	// _cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("PING", irc::ping::create));
	// _cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("PRIVMSG", irc::privmsg::create));
	// _cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("QUIT", irc::quit::create));
	// _cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("TOPIC", irc::topic::create));
	// _cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("USER", irc::user::create));

	return _cmds;
}


std::map<std::string, irc::cmd_factory::cmd_maker> irc::cmd_factory::_cmds = init();

/* default constructor */
irc::cmd_factory::cmd_factory(void) {
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
irc::cmd_factory::cmd_maker irc::cmd_factory::search(const std::string& cmd) {

	std::map<std::string, cmd_maker>::iterator	it = _cmds.find(cmd);

	if (it != _cmds.end())
		return it->second;

	return NULL;
}


