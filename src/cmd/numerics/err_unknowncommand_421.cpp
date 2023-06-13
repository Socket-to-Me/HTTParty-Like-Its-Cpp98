#include "err_unknowncommand_421.hpp"

/* default constructor */
irc::err_unknowncommand_421::err_unknowncommand_421(void) {
    return;
}

/* destructor */
irc::err_unknowncommand_421::~err_unknowncommand_421(void) {
    return;
}

/* execute command */
bool irc::err_unknowncommand_421::execute(void) {
    return false;
}

/* evaluate command */
bool irc::err_unknowncommand_421::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::err_unknowncommand_421::create(void) {
    return irc::auto_ptr<irc::cmd>(new irc::err_unknowncommand_421());
}
