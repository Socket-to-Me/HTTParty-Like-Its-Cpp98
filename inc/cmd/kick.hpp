
#ifndef KICK_HPP
# define KICK_HPP

# include "numerics.hpp"
# include "auto_ptr.hpp"
# include "cmd.hpp"

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	// -- C M D  B A S E  C L A S S -------------------------------------------

	class kick : public irc::cmd {

		public:

			// -- C O N S T R U C T O R S -------------------------------------

			/* parametric constructor */
			kick(const irc::msg&, irc::connection&);

			/* destructor */
			~kick(void);


			// -- V I R T U A L  M E T H O D S --------------------------------

			/* execute command */
			bool execute(void);

			/* evaluate command */
			bool evaluate(void);

            /* create command */
            static irc::auto_ptr<irc::cmd> create(const irc::msg&, irc::connection&);

		private:

			// -- N O N - C O P Y A B L E  C L A S S --------------------------

			/* copy constructor */
			kick(const kick&);

			/* copy assignment operator */
			kick& operator=(const kick&);


			// -- M E M B E R S --------------------------

			const irc::msg& _msg;

			irc::connection& _conn;

			std::string		_channel;
			std::string		_user;
			std::string		_comment;
	};

}

#endif
