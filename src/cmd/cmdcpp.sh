#!/bin/bash

commands=("CAP" "AUTHENTICATE" "PASS" "NICK" "USER" "PING" "PONG"
            "OPER" "QUIT" "ERROR" "JOIN" "PART" "TOPIC" "NAMES" "LIST"
            "INVITE" "KICK" "MOTD" "VERSION" "ADMIN" "CONNECT" "LUSERS"
            "TIME" "STATS" "HELP" "INFO" "MODE" "PRIVMSG" "NOTICE"
            "WHO" "WHOIS" "WHOWAS" "KILL" "REHASH" "RESTART" "SQUIT"
            "AWAY" "LINKS" "USERHOST" "WALLOPS")

for command in "${commands[@]}"; do
    lowercase_command=$(echo "$command" | tr '[:upper:]' '[:lower:]')
    filename="${lowercase_command}.cpp"  # Filename based on command name

    # Create the file with the command structure
    cat > "$filename" << EOF
#include "$lowercase_command.hpp"

/* default constructor */
irc::$lowercase_command::$lowercase_command(void) {
    return;
}

/* parametric constructor */
irc::$lowercase_command::$lowercase_command(std::vector<irc::token> tokens)
: _tokens(tokens) {
    return;
}

/* destructor */
irc::$lowercase_command::~$lowercase_command(void) {
    return;
}

/* execute command */
bool irc::$lowercase_command::execute(irc::connection& conn) {
    return false;
}

/* evaluate command */
bool irc::$lowercase_command::evaluate(void) {
    return false;
}

/* create command */
irc::auto_ptr<irc::cmd> irc::$lowercase_command::create(std::vector<irc::token> tokens) {
    return irc::auto_ptr<irc::cmd>(new irc::$lowercase_command(std::vector<irc::token> tokens));
}
EOF

    echo "Created file: $filename"
done
