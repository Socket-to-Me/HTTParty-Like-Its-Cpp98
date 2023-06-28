#ifndef CMD_HEADER
#define CMD_HEADER

#include "auto_ptr.hpp"
#include "msg.hpp"
#include "connection.hpp"
#include "lexer.hpp"


// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {


	// -- C M D  B A S E  C L A S S -------------------------------------------

	class cmd {

		public:

			// -- C O N S T R U C T O R S -------------------------------------

			/* default constructor */
			cmd(void);

			/* destructor */
			virtual ~cmd(void);


			// -- V I R T U A L  M E T H O D S --------------------------------

			/* execute command */
			virtual bool execute(void) = 0;

			/* evaluate command */
			virtual bool evaluate(void) = 0;


		private:

			// -- N O N - C O P Y A B L E  C L A S S --------------------------

			/* copy constructor */
			cmd(const cmd&);

			/* copy assignment operator */
			cmd& operator=(const cmd&);

	};

}


#endif
