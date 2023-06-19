#include "whois.hpp"

/* default constructor */
irc::whois::whois(void) {
    return;
}

/* parametric constructor */
irc::whois::whois(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::whois::~whois(void) {
    return;
}

/* execute command */
bool irc::whois::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::whois::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::whois::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::whois(std::vector<irc::token> tokens));
}
