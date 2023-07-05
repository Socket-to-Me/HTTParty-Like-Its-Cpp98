#include "channel.hpp"

// -- public constructors -----------------------------------------

/* parametric constructor */
irc::channel::channel(const std::string& name)
: _name(name) {

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

const std::vector<irc::connection*>&  irc::channel::getoperators(void) const {
	return _operators;
}

const std::vector<irc::connection*>&  irc::channel::getconnections(void) const {
	return _connections;
}

std::string  irc::channel::getconnectionsasstr(void) const {

	std::vector<irc::connection*>::const_iterator it;
	std::string result;

	for (it = _connections.begin(); it != _connections.end(); ++it) {
		if (isOperator(**it)) {
			result += "@";
		}
		result += (*it)->getnick();
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

void  irc::channel::setmode(const irc::connection& op, const std::vector<std::string>& params) {
    
	std::string modestring = params[0];

    if (isOperator(op)) {

		bool setting = false;

		for (size_t i = 0; i < str.length(); ++i) {

			if (str[i] == '+') {
				setting = true;

			} else if (str[i] == '-') {
				setting = false;

			} else {

				switch (str[i]) {

					case 'i':
						_mode_invite_only = setting;
						break;

					case 't':
						_mode_topic_restricted = setting;
						break;

					case 'k':
						_mode_channel_key = setting; //TODO WITH ARG
						break;

					case 'o':
						_mode_operator_privileges = setting; //TODO WITH ARG
						break;

					case 'l':
						_mode_user_limit = setting;
						break;

					default:
						break;
				}
			}
		}

		op.send(":" + op.getnick() + " MODE " + _target + " " + modestring + "\r\n");

    }

    return;
}

bool irc::channel::check_modestring(const std::string& str) {

    if (str.empty()) {
        return false;  // Empty string is not valid
    }

    bool hasPlus = false;
    bool hasMinus = false;
	std::unordered_set<char> modeChars;

    if (str[0] != '+' && str[0] != '-') {
        return false;  // First character should be '+' or '-'
    }

    for (size_t i = 1; i < str.length(); ++i) {

        if (!std::isalpha(str[i])) {

            if (str[i] == '+') {
                if (hasPlus) {
                    return false;  	// Multiple '+' characters found
                }
                hasPlus = true;

            } else if (str[i] == '-') {
                if (hasMinus) {
                    return false; 	// Multiple '-' characters found
                }
                hasMinus = true;

            } else {

				switch (str[i]) {

                    case 'i':
                    case 't':
                    case 'k':
                    case 'o':
                    case 'l':
                        if (!modeChars.insert(str[i]).second) {
                            return false;  	// Duplicate mode character found
                        }
                        break;

					default:
						return false; 		// Invalid mode character
						break;
				}

            }
        }
    }

    return true;
}


void  irc::channel::setkey(const irc::connection& op, const std::string& str) {

	if (isOperator(op)) {

		_key = str;
	}
	return;
}

bool  irc::channel::checkPassword(const std::string& password) const {

	if (getkey().length()) {
		if (password != getkey()) {
			return false;
		}
	}
	return true;
}

void irc::channel::addOperator(irc::connection& conn) {

	_operators.push_back(&conn);
}

void irc::channel::addUser(irc::connection& conn) {

	_connections.push_back(&conn);
}

void irc::channel::removeUser(irc::connection& conn) {

	std::vector<irc::connection*>::iterator	it;

	for (it=_connections.begin(); it!=_connections.end(); ++it) {
		if (*it == &conn) {
			_connections.erase(it);
			break;
		}
	}

	removeOperator(conn);
}

void irc::channel::removeOperator(irc::connection& conn) {

	std::vector<irc::connection*>::iterator	it;

	for (it=_operators.begin(); it!=_operators.end(); ++it) {
		if (*it == &conn) {
			_operators.erase(it);
			break;
		}
	}
}

void irc::channel::kick(const irc::connection& op, irc::connection& conn) {

	if (isOperator(op)) {

		removeUser(conn);

	}
}

void irc::channel::invite(const irc::connection& op, irc::connection& conn) {

	if (isOperator(op)) {

		addUser(conn);
	}
}

void irc::channel::giveOperatorPrivilege(const irc::connection& op, irc::connection& conn) {

	if (isOperator(op)) {

		addOperator(conn);
	}
}

void irc::channel::takeOperatorPrivilege(const irc::connection& op, irc::connection& conn) {

	if (isOperator(op)) {

		removeOperator(conn);
	}
}

bool irc::channel::broadcast(const std::string& msg) {

	std::vector<irc::connection*>::iterator	it;

	for (it=_connections.begin(); it!=_connections.end(); ++it) {
		if ((*it)->send(msg) <= 0) {
			return false;
		}
	}
	return true;
}

bool irc::channel::send(const std::string& nick, const std::string& msg) {

	std::vector<irc::connection*>::iterator	it;

	for (it=_connections.begin(); it!=_connections.end(); ++it) {
		if ((*it)->getnick() == nick) {
			if ((*it)->send(msg) <= 0) {
				return false;
			}
			break;
		}
	}
	return true;
}

void irc::channel::set_mode_channel_key(bool val) {

	_mode_channel_key = val;
}

bool irc::channel::is_mode_channel_key(void) {

	return _mode_channel_key;
}

std::string irc::channel::getsymbol(void) const {

	if (_mode_channel_key) {
		return "*";
	} else {
		return "=";
	}
}

/* default constructor */
irc::channel::channel(void) {
	return;
}

// -- private methods ----------------------------------------------
const std::string&  irc::channel::getkey(void) const {
	return _key;
}

bool irc::channel::isConnection(const irc::connection& conn) const {

	std::vector<irc::connection*>::const_iterator	it;

    for (it=_connections.begin(); it!=_connections.end(); it++) {
        if (**it == conn) {
            return true;
        }
    }
    return false;
}

bool irc::channel::isOperator(const irc::connection& op) const {

	std::vector<irc::connection*>::const_iterator	it;

    for (it=_operators.begin(); it!=_operators.end(); it++) {
        if (**it == op) {
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
