#!/bin/bash

commands=("CAP" "AUTHENTICATE" "PASS" "NICK" "USER" "PING" "PONG"
            "OPER" "QUIT" "ERROR" "JOIN" "PART" "TOPIC" "NAMES" "LIST"
            "INVITE" "KICK" "MOTD" "VERSION" "ADMIN" "CONNECT" "LUSERS"
            "TIME" "STATS" "HELP" "INFO" "MODE" "PRIVMSG" "NOTICE"
            "WHO" "WHOIS" "WHOWAS" "KILL" "REHASH" "RESTART" "SQUIT"
            "AWAY" "LINKS" "USERHOST" "WALLOPS")

for command in "${commands[@]}"; do
    lowercase_command=$(echo "$command" | tr '[:upper:]' '[:lower:]')
    filename="${lowercase_command}.hpp"  # Filename based on command name

    # Create the file with the command structure
    cat > "$filename" << EOF

#ifndef ${command}_HPP
# define ${command}_HPP

# include "numerics.hpp"
# include "auto_ptr.hpp"
# include "cmd.hpp"

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	// -- C M D  B A S E  C L A S S -------------------------------------------

	class $lowercase_command : public irc::cmd {

		public:

			// -- C O N S T R U C T O R S -------------------------------------

			/* default constructor */
			$lowercase_command(void);

			/* parametric constructor */
			$lowercase_command(std::vector<irc::token> tokens);

			/* destructor */
			~$lowercase_command(void);


			// -- V I R T U A L  M E T H O D S --------------------------------

			/* execute command */
			bool execute(irc::connection& conn);

			/* evaluate command */
			bool evaluate(void);

            /* create command */
            static irc::auto_ptr<irc::cmd> create(std::vector<irc::token> tokens);

		private:

			// -- N O N - C O P Y A B L E  C L A S S --------------------------

			/* copy constructor */
			$lowercase_command(const $lowercase_command&);

			/* copy assignment operator */
			$lowercase_command& operator=(const $lowercase_command&);

			// -- M E M B E R S --------------------------
			std::vector<irc::token>	_tokens;

	};

}

#endif
EOF

    echo "Created file: $filename"
done
