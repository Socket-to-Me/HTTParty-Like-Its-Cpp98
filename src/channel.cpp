#include "channel.hpp"
#include "server.hpp"

// -- public constructors -----------------------------------------

/* default constructor */
irc::channel::channel(void)
: _name(""),
  _topic(""),
  _key(""),
  _limit(0),
  _operators(),
  _connections(),
  _invitations(),
  _mode_invite_only(false),
  _mode_topic_restricted(false),
  _mode_user_limit(false),
  _mode_channel_key(false) {
}

/* parametric constructor */
irc::channel::channel(const std::string& name)
: _name(name),
  _topic(""),
  _key(""),
  _limit(0),
  _operators(),
  _connections(),
  _invitations(),
  _mode_invite_only(false),
  _mode_topic_restricted(false),
  _mode_user_limit(false),
  _mode_channel_key(false) {

	return;
}

/* copy constructor */
irc::channel::channel(const channel& other)
: _name(other._name),
  _topic(other._topic),
  _key(other._key),
  _limit(other._limit),
  _operators(other._operators),
  _connections(other._connections),
  _invitations(other._invitations),

  _mode_invite_only(other._mode_invite_only),
  _mode_topic_restricted(other._mode_topic_restricted),
  _mode_user_limit(other._mode_user_limit),
  _mode_channel_key(other._mode_channel_key) {

	return;
}

/* copy assignment operator */
irc::channel& irc::channel::operator=(const irc::channel& other) {

	if (this != &other) // not a self-assignment
	{
		_name = other._name;
		_topic = other._topic;
		_key = other._key;
		_limit = other._limit;
		_operators = other._operators;
		_connections = other._connections;
		_invitations = other._invitations;
		_mode_invite_only = other._mode_invite_only;
		_mode_topic_restricted = other._mode_topic_restricted;
		_mode_user_limit = other._mode_user_limit;
		_mode_channel_key = other._mode_channel_key;

	}
	return *this;
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

size_t	irc::channel::getlimit(void) const {
	return _limit;
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

    std::string mode = "+o";

    if (_mode_invite_only)
        mode += "i";
    if (_mode_topic_restricted)
        mode += "t";
    if (_mode_user_limit)
        mode += "l";
    if (_mode_channel_key)
        mode += "k";

    return mode;
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

bool  irc::channel::setmode(const irc::connection& op, const std::vector<std::string>& params) {

	std::string modestring = params[1];
	const std::vector<std::string>& args = std::vector<std::string>(params.begin() + 2, params.end());

    if (isOperator(op)) {

		bool setting = false;

		for (size_t i = 0; i < modestring.length(); ++i) {

			if (modestring[i] == '+') {
				setting = true;

			} else if (modestring[i] == '-') {
				setting = false;

			} else {

				switch (modestring[i]) {

					case 'i':
						_mode_invite_only = setting;
						break;

					case 't':
						_mode_topic_restricted = setting;
						break;

					case 'k':

						if (setting == false) {
							_key.clear();
							_mode_channel_key = false;

						} else {
							std::string	key = args[0];
							_key = key;
							_mode_channel_key = true;

						}
						break;

					case 'o':

						for (std::vector<std::string>::const_iterator it = args.begin(); it != args.end(); ++it) {

							if (irc::server::instance().isNickInUse(*it)) {

								irc::connection& conn = irc::server::instance().getconnection(*it);

								if (setting == true) {
									addOperator(conn);

								} else {
									removeOperator(conn);
								}

							} else {
								return false;
							}
						}
						break;

					case 'l':

						if (setting == false) {
							_limit = 0;
							_mode_user_limit = false;

						} else {
							std::string	limit = args[0];
							std::istringstream iss(limit);
							iss >> _limit;
							_mode_user_limit = true;
						}
						break;

					default:
						break;
				}
			}
		}

    }

    return true;
}

bool irc::channel::check_modestring(const std::string& str) const {

    if (str.empty()) {
        return false;  // Empty string is not valid
    }

    bool hasPlus = false;
    bool hasMinus = false;
	std::string modeChars;

    if (str[0] != '+' && str[0] != '-') {
        return false;  // First character should be '+' or '-'
    }

    for (size_t i = 1; i < str.length(); ++i) {

        if (std::isalpha(str[i])) {

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
                        if (modeChars.find(str[i]) != std::string::npos) {
                            return false;  	// Duplicate mode character found
                        }
						modeChars += str[i];
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

bool irc::channel::broadcastNumeric(const std::string& target, const std::string& (*numfn)(irc::connection&)) {

	std::vector<irc::connection*>::iterator	it;

	for (it=_connections.begin(); it!=_connections.end(); ++it) {

		irc::connection&	conn = **it;
		conn.settarget(target);
		conn.setchannelname(_name);

		if (conn.send((*numfn)(conn)) <= 0) {
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

// --------------------------------------------------

void irc::channel::addOperator(irc::connection& conn) {

	_operators.push_back(&conn);
}

void irc::channel::addUser(irc::connection& conn) {

	_connections.push_back(&conn);
}

void irc::channel::addInvitation(irc::connection& conn) {

	_invitations.push_back(&conn);
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

void irc::channel::removeInvitation(irc::connection& conn) {

	std::vector<irc::connection*>::iterator	it;

	for (it=_invitations.begin(); it!=_invitations.end(); ++it) {
		if (*it == &conn) {
			_invitations.erase(it);
			break;
		}
	}
}

// --------------------------------------------------

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

bool irc::channel::isInvited(const irc::connection& conn) const {

	std::vector<irc::connection*>::const_iterator	it;

    for (it=_invitations.begin(); it!=_invitations.end(); it++) {
        if (**it == conn) {
            return true;
        }
    }
    return false;
}

// --------------------------------------------------

bool irc::channel::is_mode_invite_only(void) {

	return _mode_invite_only;
}

bool irc::channel::is_mode_topic_restricted(void) {

	return _mode_topic_restricted;
}

bool irc::channel::is_mode_user_limit(void) {

	return _mode_user_limit;
}

bool irc::channel::is_mode_channel_key(void) {

	return _mode_channel_key;
}

// --------------------------------------------------

void irc::channel::set_mode_invite_only(bool setting) {

	_mode_invite_only = setting;
}

void irc::channel::set_mode_topic_restricted(bool setting) {

	_mode_topic_restricted = setting;
}

void irc::channel::set_mode_user_limit(bool setting) {

	_mode_user_limit = setting;
}

void irc::channel::set_mode_channel_key(bool setting) {

	_mode_channel_key = setting;
}

// --------------------------------------------------

std::string irc::channel::getsymbol(void) const {

	if (_mode_channel_key) {
		return "*";
	} else {
		return "=";
	}
}

// --------------------------------------------------


// -- private methods ----------------------------------------------
const std::string&  irc::channel::getkey(void) const {
	return _key;
}

// -- private assignment operator ----------------------------------

