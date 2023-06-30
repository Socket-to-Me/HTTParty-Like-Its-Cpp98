
#ifndef QUIT_HPP
# define QUIT_HPP

# include "numerics.hpp"
# include "auto_ptr.hpp"
# include "cmd.hpp"


// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {


	// -- Q U I T -------------------------------------------------------------

	class quit : public irc::cmd {


		public:

			// -- public constructors -----------------------------------------

			/* parametric constructor */
			quit(const irc::msg&, irc::connection&);

			/* copy constructor */
			quit(const quit&);

			/* destructor */
			~quit(void);



			// -- public overriden methods ------------------------------------

			/* execute command */
			bool execute(void);

			/* evaluate command */
			bool evaluate(void);


			// -- public static methods ---------------------------------------

            /* create command */
            static irc::auto_ptr<irc::cmd> create(const irc::msg&, irc::connection&);

			/* send */
			static void send(irc::connection&);


		private:

			// -- private assignment operators --------------------------------

			/* copy assignment operator */
			quit& operator=(const quit&);


			// -- private members ---------------------------------------------

			/* message reference */
			const irc::msg& _msg;

			/* connection reference */
			irc::connection& _conn;

	};

}

#endif
