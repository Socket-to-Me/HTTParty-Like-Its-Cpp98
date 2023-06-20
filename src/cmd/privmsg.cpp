#include "privmsg.hpp"

/* default constructor */
irc::privmsg::privmsg(void) {
    return;
}

/* parametric constructor */
irc::privmsg::privmsg(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::privmsg::~privmsg(void) {
    return;
}

/* execute command */
bool irc::privmsg::execute(void) {
    return false;
}

/* evaluate command */
bool irc::privmsg::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::privmsg::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::privmsg(tokens));
}
