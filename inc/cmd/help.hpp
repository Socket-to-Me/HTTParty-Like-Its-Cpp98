
#ifndef HELP_HPP
# define HELP_HPP

# include "auto_ptr.hpp"
# include "cmd.hpp"

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	// -- C M D  B A S E  C L A S S -------------------------------------------

	class help : public irc::cmd {

		public:

			// -- C O N S T R U C T O R S -------------------------------------

			/* default constructor */
			help(void);

			/* destructor */
			~help(void);


			// -- V I R T U A L  M E T H O D S --------------------------------

			/* execute command */
			bool execute(void);

			/* evaluate command */
			bool evaluate(void);

            /* create command */
            static irc::auto_ptr<irc::cmd> create(void);

		private:

			// -- N O N - C O P Y A B L E  C L A S S --------------------------

			/* copy constructor */
			help(const help&);

			/* copy assignment operator */
			help& operator=(const help&);

	};

}

#endif
