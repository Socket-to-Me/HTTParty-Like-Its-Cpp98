#include "cmd_factory.hpp"

std::map<std::string, irc::cmd_factory::cmd_maker>	init(void) {

	std::map<std::string, irc::cmd_factory::cmd_maker> _cmds;

	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("CAP", irc::cap::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("AUTHENTICATE", irc::authenticate::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("PASS", irc::pass::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("NICK", irc::nick::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("USER", irc::user::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("PING", irc::ping::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("PONG", irc::pong::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("OPER", irc::oper::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("QUIT", irc::quit::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("ERROR", irc::error::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("JOIN", irc::join::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("PART", irc::part::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("TOPIC", irc::topic::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("NAMES", irc::names::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("LIST", irc::list::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("INVITE", irc::invite::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("KICK", irc::kick::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("MOTD", irc::motd::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("VERSION", irc::version::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("ADMIN", irc::admin::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("CONNECT", irc::connect::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("LUSERS", irc::lusers::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("TIME", irc::time::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("STATS", irc::stats::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("HELP", irc::help::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("INFO", irc::info::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("MODE", irc::mode::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("PRIVMSG", irc::privmsg::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("NOTICE", irc::notice::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("WHO", irc::who::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("WHOIS", irc::whois::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("WHOWAS", irc::whowas::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("KILL", irc::kill::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("REHASH", irc::rehash::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("RESTART", irc::restart::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("SQUIT", irc::squit::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("AWAY", irc::away::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("LINKS", irc::links::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("USERHOST", irc::userhost::create));
	_cmds.insert(std::pair<std::string, irc::cmd_factory::cmd_maker>("WALLOPS", irc::wallops::create));

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


