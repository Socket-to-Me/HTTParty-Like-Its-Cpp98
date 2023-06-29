#ifndef PASS_HEADER
# define PASS_HEADER

# include "msg.hpp"
# include "numerics.hpp"
# include "auto_ptr.hpp"
# include "cmd.hpp"


// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {


	// -- P A S S -------------------------------------------------------------

	class pass : public irc::cmd {


		public:

			// -- public constructors -----------------------------------------

			/* parametric constructor */
			pass(const irc::msg&, irc::connection&);

			/* destructor */
			~pass(void);


			// -- public overloaded methods -----------------------------------

			/* execute command */
			bool execute(void);

			/* evaluate command */
			bool evaluate(void);


			// -- public static methods ---------------------------------------

            /* create command */
            static irc::auto_ptr<irc::cmd> create(const irc::msg&, irc::connection&);


		private:

			// -- private members ---------------------------------------------

			/* parsed message */
			const irc::msg& _msg;

			/* client connection */
			irc::connection& _conn;

	};

}

#endif
