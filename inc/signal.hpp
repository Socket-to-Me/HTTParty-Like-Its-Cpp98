#ifndef SIGNAL_HEADER
#define SIGNAL_HEADER

#include "server.hpp"

#include <signal.h>
#include <termios.h>


// -- N A M E S P A C E  I R C ------------------------------------------------

namespace irc {


	// -- S I G N A L ---------------------------------------------------------

	class signal {


		public:

			// -- public constructors -----------------------------------------

			/* default constructor */
			signal(void);

			/* destructor */
			~signal(void);


		private:

			// -- private static methods --------------------------------------

			/* ctrl-c handler */
			static void	handler(int);


	};

}

#endif
