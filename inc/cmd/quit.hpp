
#ifndef QUIT_HPP
# define QUIT_HPP

# include "numerics.hpp"
# include "auto_ptr.hpp"
# include "cmd.hpp"

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	// -- C M D  B A S E  C L A S S -------------------------------------------

	class quit : public irc::cmd {

		public:

			// -- C O N S T R U C T O R S -------------------------------------

			/* default constructor */
			quit(void);

			/* parametric constructor */
			quit(std::vector<irc::token> tokens);

			/* destructor */
			~quit(void);


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
			quit(const quit&);

			/* copy assignment operator */
			quit& operator=(const quit&);

			// -- M E M B E R S --------------------------
			std::vector<irc::token>	_tokens;

	};

}

#endif
