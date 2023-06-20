#include "channel.hpp"

// -- public constructors -----------------------------------------

/* parametric constructor */
irc::channel::channel(const std::string& name, const std::string& topic)
: _name(name), _topic(topic) {

	return;
}

/* copy constructor */
irc::channel::channel(const channel& other) 
: _name(other._name), _topic(other._topic), _mode(other._mode), _key(other._key) {

	return;
}

/* destructor */
~channel(void);

// -- public accessors --------------------------------------------
const std::string&  getname(void) const;
const std::string&  gettopic(void) const;
const std::string&  getmode(void) const;
const std::string&  getkey(void) const;

// -- public methods ----------------------------------------------
void  setname(const irc::connection& op, const std::string& str);
void  settopic(const irc::connection& op, const std::string& str);
void  setmode(const irc::connection& op, const std::string& str);
void  setkey(const irc::connection& op, const std::string& str);

void kick(const irc::connection& op, const irc::connection& conn);
void invite(const irc::connection& op, const irc::connection& conn);
void giveOperatorPrivilege(const irc::connection& op, const irc::connection& conn);
void takeOperatorPrivilege(const irc::connection& op, const irc::connection& conn);

/* default constructor */
channel(void);

// -- private assignment operator ----------------------------------

/* copy assignment operator */
channel& operator=(const channel&);
