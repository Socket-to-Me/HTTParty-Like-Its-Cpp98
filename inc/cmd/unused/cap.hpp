
#ifndef CAP_HPP
# define CAP_HPP

# include "numerics.hpp"
# include "auto_ptr.hpp"
# include "cmd.hpp"

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	// -- C M D  B A S E  C L A S S -------------------------------------------

	class cap : public irc::cmd {

		public:

			// -- C O N S T R U C T O R S -------------------------------------

			/* default constructor */
			cap(void);

			/* parametric constructor */
			cap(std::vector<irc::token> tokens);

			/* destructor */
			~cap(void);


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
			cap(const cap&);

			/* copy assignment operator */
			cap& operator=(const cap&);

			// -- M E M B E R S --------------------------
			std::vector<irc::token>	_tokens;

	};

}

#endif
