#include "whois.hpp"

/* default constructor */
irc::whois::whois(void) {
    return;
}

/* destructor */
irc::whois::~whois(void) {
    return;
}

/* execute command */
bool irc::whois::execute(void) {
    return false;
}

/* evaluate command */
bool irc::whois::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::whois::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::whois());
}
