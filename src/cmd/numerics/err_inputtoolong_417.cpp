#include "err_inputtoolong_417.hpp"

/* default constructor */
irc::err_inputtoolong_417::err_inputtoolong_417(void) {
    return;
}

/* destructor */
irc::err_inputtoolong_417::~err_inputtoolong_417(void) {
    return;
}

/* execute command */
bool irc::err_inputtoolong_417::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_inputtoolong_417::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_inputtoolong_417::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_inputtoolong_417());
}
