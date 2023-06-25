#include "parser.hpp"


// -- M S G -------------------------------------------------------------------


// -- public constructors -----------------------------------------------------

/* default constructor */
irc::msg::msg(void)
: _tags(),
  _source(),
  _command(),
  _params(),
  _nick(),
  _user(),
  _host() {
}

/* copy constructor */
irc::msg::msg(const irc::msg& msg)
: _tags(msg._tags),
  _source(msg._source),
  _command(msg._command),
  _params(msg._params),
  _nick(msg._nick),
  _user(msg._user),
  _host(msg._host) {
}

/* destructor */
irc::msg::~msg(void) {
}


// -- public assignment operators ---------------------------------------------

/* copy assignment operator */
irc::msg& irc::msg::operator=(const irc::msg& msg) {
	// check for self-assignment
	if (this == &msg) {
		_tags = msg._tags;
		_source = msg._source;
		_command = msg._command;
		_params = msg._params;
		_nick = msg._nick;
		_user = msg._user;
		_host = msg._host;
	} // return self reference
	return *this;
}


// -- public accessors --------------------------------------------------------

/* have tags */
bool irc::msg::have_tags(void) const {
	return !_tags.empty();
}

/* have source */
bool irc::msg::have_source(void) const {
	return !_source.empty();
}

/* have command */
bool irc::msg::have_command(void) const {
	return !_command.empty();
}

/* have params */
bool irc::msg::have_params(void) const {
	return !_params.empty();
}

/* have nick */
bool irc::msg::have_nick(void) const {
	return !_nick.empty();
}

/* have user */
bool irc::msg::have_user(void) const {
	return !_user.empty();
}

/* have host */
bool irc::msg::have_host(void) const {
	return !_host.empty();
}


/* get tags */
const irc::msg::tags& irc::msg::get_tags(void) const {
	return _tags;
}

/* get source */
const irc::msg::source& irc::msg::get_source(void) const {
	return _source;
}

/* get command */
const irc::msg::command& irc::msg::get_command(void) const {
	return _command;
}

/* get params */
const irc::msg::params& irc::msg::get_params(void) const {
	return _params;
}

/* get nick */
const irc::msg::nick& irc::msg::get_nick(void) const {
	return _nick;
}

/* get user */
const irc::msg::user& irc::msg::get_user(void) const {
	return _user;
}

/* get host */
const irc::msg::host& irc::msg::get_host(void) const {
	return _host;
}


// -- P A R S E R -------------------------------------------------------------


// -- private constructors ----------------------------------------------------

/* default constructor */
irc::parser::parser(void) {
}

/* copy constructor */
irc::parser::parser(const irc::parser& parser) {
}

/* destructor */
irc::parser::~parser(void) {
}


static bool not_space(int ch) {
	return !std::isspace(ch);
}


// -- public static methods ---------------------------------------------------

/* parse */
irc::msg irc::parser::parse(const std::string& msg) {

	//std::vector<irc::token> tokens;

	irc::msg message;

	// trim leading and trailing white spaces
	std::string trim_line = msg;

	trim_line.erase(trim_line.begin(), std::find_if(trim_line.begin(), trim_line.end(), not_space));

	trim_line.erase(std::find_if(trim_line.rbegin(), trim_line.rend(), not_space).base(), trim_line.end());

	// loop over the message
	for (std::string::size_type i = 0; i < trim_line.size(); ++i) {

		// tag parsing
		if (trim_line[i] == '@') {
			// parse tags
			while (trim_line[i] != ' ' && i < trim_line.size()) {
				std::string tag;
				while (trim_line[i] != ';' && trim_line[i] != ' ' && i < trim_line.size()) {
					tag += trim_line[i++];
				}
				std::string::size_type separator_pos = tag.find('=');
				if (separator_pos != std::string::npos) {
					std::string key = tag.substr(0, separator_pos);
					std::string value = tag.substr(separator_pos + 1);
					message._tags.push_back(std::make_pair(key, value));
				}
				if (i < trim_line.size() && trim_line[i] == ';') ++i;
			}
		}

		// source parsing
		if (trim_line[i] == ':') {
			// parse source
			++i;  // skip ':'
			while (trim_line[i] != ' ' && i < trim_line.size()) {
				message._source += trim_line[i++];
			}
		}


		// command parsing
		if (trim_line[i] == ' ' || i == trim_line.size()) {
			// parse command
			while (trim_line[i] != ' ' && i < trim_line.size()) {
				message._command += trim_line[i++];
			}
		}

		// parameters parsing
		while (i < trim_line.size()) {
			std::string param;
			while (trim_line[i] != ' ' && i < trim_line.size()) {
				param += trim_line[i++];
			}
			message._params.push_back(param);
			if (i < trim_line.size() && trim_line[i] == ' ') ++i;
		}


	}

	return message;
}
