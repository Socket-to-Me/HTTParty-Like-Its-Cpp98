#ifndef JOIN_HEADER
#define JOIN_HEADER

#include <iostream>
#include "auto_ptr.hpp"
#include "cmd.hpp"

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	class join : public irc::cmd {

		public:

			// -- C O N S T R U C T O R S -------------------------------------

			/* default constructor */
			join(void);

			/* destructor */
			~join(void);


			// -- O V E R R I D E  M E T H O D S ------------------------------

			/* execute command */
			bool execute(void);

			/* evaluate command */
			bool evaluate(void);

			/* create command */
			static auto_ptr<cmd> create(void);


		private:

			// -- N O N - C O P Y A B L E  C L A S S --------------------------

			/* copy constructor */
			join(const join& j);

			/* copy assignment operator */
			join& operator=(const join& j);

	};

}




#endif

