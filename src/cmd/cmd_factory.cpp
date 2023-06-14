#include "cmd_factory.hpp"

std::map<std::string, irc::cmd_factory::cmd_maker>	init(void) {

	std::map<std::string, irc::cmd_factory::cmd_maker> _cmds;

	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("JOIN", irc::join::create));

	// "CAP" "AUTHENTICATE" "PASS" "NICK" "USER" "PING" "PONG"
	// "OPER" "QUIT" "ERROR" "JOIN" "PART" "TOPIC" "NAMES" "LIST"
	// "INVITE" "KICK" "MOTD" "VERSION" "ADMIN" "CONNECT" "LUSERS"
	// "TIME" "STATS" "HELP" "INFO" "MODE" "PRIVMSG" "NOTICE"
	// "WHO" "WHOIS" "WHOWAS" "KILL" "REHASH" "RESTART" "SQUIT"
	// "AWAY" "LINKS" "USERHOST" "WALLOPS"

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


