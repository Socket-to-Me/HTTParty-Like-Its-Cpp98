#include "msg.hpp"


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

