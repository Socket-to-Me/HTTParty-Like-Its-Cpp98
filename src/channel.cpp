#include "channel.hpp"

// -- public constructors -----------------------------------------

/* parametric constructor */
irc::channel::channel(const std::string& name, const std::string& topic)
: _name(name), _topic(topic) {

	return;
}

/* copy constructor */
irc::channel::channel(const channel& other) 
: _name(other._name), _topic(other._topic), _key(other._key) {

	return;
}

/* destructor */
irc::channel::~channel(void) {
	return;
}

// -- public accessors --------------------------------------------
const std::string&  irc::channel::getname(void) const {
	return _name;
}

const std::string&  irc::channel::gettopic(void) const {
	return _topic;
}

const std::vector<irc::connection>&  irc::channel::getoperators(void) const {
	return _operators;
}

const std::vector<irc::connection>&  irc::channel::getconnections(void) const {
	return _connections;
}

std::string  irc::channel::getconnectionsasstr(void) const {

	std::string result;

	for (std::vector<irc::connection>::const_iterator it = _connections.begin(); it != _connections.end(); ++it) {
		if (isOperator(*it)) {
			result += "@";
		}
		result += it->getnick();
		if (it != _connections.end() - 1) {
			result += " ";
		}
	}

	return result;
}

// -- public methods ----------------------------------------------

const std::string irc::channel::getmode(void) const {

    std::string mode;

    if (_mode_invite_only)
        mode += "i";
    if (_mode_topic_restricted)
        mode += "t";
    if (_mode_user_limit)
        mode += "l";
    if (_mode_channel_key)
        mode += "k";
    if (_mode_operator_privileges)
        mode += "o";
    if (_mode_ban)
        mode += "b";

    if (mode.size())
        return mode.insert(0, "+");
    return "";
}

void  irc::channel::setname(const irc::connection& op, const std::string& str) {

	if (isOperator(op)) {

		_name = str;
	}
	return;
}

void  irc::channel::settopic(const irc::connection& op, const std::string& str) {

	if (isOperator(op)) {

		_topic = str;
	}
	return;
}

void  irc::channel::setmode(const irc::connection& op, const std::string& s) {

	if (isOperator(op)) {

		if (s.find('+') != std::string::npos) {

			if (s.find('i') != std::string::npos)
				_mode_invite_only = true;
			if (s.find('t') != std::string::npos)
				_mode_topic_restricted = true;
			if (s.find('l') != std::string::npos)
				_mode_user_limit = true;
			if (s.find('k') != std::string::npos)
				_mode_channel_key = true;
			if (s.find('o') != std::string::npos)
				_mode_operator_privileges = true;
			if (s.find('b') != std::string::npos)
				_mode_ban = true;

		}
		else {

			if (s.find('i') != std::string::npos)
				_mode_invite_only = false;
			if (s.find('t') != std::string::npos)
				_mode_topic_restricted = false;
			if (s.find('l') != std::string::npos)
				_mode_user_limit = false;
			if (s.find('k') != std::string::npos)
				_mode_channel_key = false;
			if (s.find('o') != std::string::npos)
				_mode_operator_privileges = false;
			if (s.find('b') != std::string::npos)
				_mode_ban = false;

		}

	}
	return;
}

void  irc::channel::setkey(const irc::connection& op, const std::string& str) {

	if (isOperator(op)) {

		_key = str;
	}
	return;
}

void irc::channel::addUser(irc::connection& conn) {

	_connections.push_back(conn);
}

void irc::channel::removeUser(irc::connection& conn) {

	std::vector<irc::connection>::iterator	it;

	for (it=_connections.begin(); it!=_connections.end(); it++) {
		if (*it == conn) {
			_connections.erase(it);
			break;
		}
	}
}


void irc::channel::kick(const irc::connection& op, irc::connection& conn) {

	if (isOperator(op)) {

		std::vector<irc::connection>::iterator	it;
		
		for (it=_operators.begin(); it!=_operators.end(); it++) {
			if (*it == conn) {
				_operators.erase(it);
				break;
			}
		}

		for (it=_connections.begin(); it!=_connections.end(); it++) {
			if (*it == conn) {
				_connections.erase(it);
				break;
			}
		}

	}
	return;
}

void irc::channel::invite(const irc::connection& op, irc::connection& conn) {

	if (isOperator(op)) {

		_connections.push_back(conn);
	}
	return;
}

void irc::channel::giveOperatorPrivilege(const irc::connection& op, irc::connection& conn) {

	if (isOperator(op)) {

		_operators.push_back(conn);
	}
	return;
}

void irc::channel::takeOperatorPrivilege(const irc::connection& op, irc::connection& conn) {

	if (isOperator(op)) {

		for (std::vector<irc::connection>::iterator it=_operators.begin(); it!=_operators.end(); it++) {
			if (*it == conn) {
				_operators.erase(it);
				break;
			}
		}
	}
	return;
}


/* default constructor */
irc::channel::channel(void) {
	return;
}

// -- private methods ----------------------------------------------
const std::string&  irc::channel::getkey(void) const {
	return _key;
}

bool irc::channel::isOperator(const irc::connection& op) const {

    for (std::vector<irc::connection>::const_iterator it=_operators.begin(); it!=_operators.end(); it++) {
        if (*it == op) {
            return true;
        }
    }
    return false;
}

// -- private assignment operator ----------------------------------

/* copy assignment operator */
irc::channel& irc::channel::operator=(const irc::channel& other) {

	if (this != &other) // not a self-assignment
	{
		_name = other.getname();
		_topic = other.gettopic();
		_key = other.getmode();
		_operators = other.getoperators();
		_connections = other.getconnections();

	}
	return *this;
}
