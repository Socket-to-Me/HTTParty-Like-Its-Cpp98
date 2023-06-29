
#ifndef PRIVMSG_HPP
# define PRIVMSG_HPP

# include "numerics.hpp"
# include "auto_ptr.hpp"
# include "cmd.hpp"

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	// -- C M D  B A S E  C L A S S -------------------------------------------

	class privmsg : public irc::cmd {

		public:

			// -- C O N S T R U C T O R S -------------------------------------

			/* parametric constructor */
			privmsg(const irc::msg&, irc::connection&);

			/* destructor */
			~privmsg(void);


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
			privmsg(const privmsg&);

			/* copy assignment operator */
			privmsg& operator=(const privmsg&);

			// -- M E M B E R S --------------------------

			const irc::msg&		_msg;
			irc::connection&	_conn;
			std::string			_target;
			std::string			_str;
			bool				_ischannel;

	};

}

#endif
