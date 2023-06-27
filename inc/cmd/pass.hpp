
#ifndef PASS_HPP
# define PASS_HPP

# include "server.hpp"
# include "numerics.hpp"
# include "auto_ptr.hpp"
# include "cmd.hpp"

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	// -- C M D  B A S E  C L A S S -------------------------------------------

	class pass : public irc::cmd {

		public:

			// -- C O N S T R U C T O R S -------------------------------------

			/* default constructor */
			pass(void);

			/* parametric constructor */
			// pass(const std::data& data);

			/* destructor */
			~pass(void);


			// -- V I R T U A L  M E T H O D S --------------------------------

			/* execute command */
			bool execute(void);

			/* evaluate command */
			bool evaluate(void);

            /* create command */
            static irc::auto_ptr<irc::cmd> create(std::vector<irc::token> tokens);

		private:

			// -- N O N - C O P Y A B L E  C L A S S --------------------------

			/* copy constructor */
			pass(const pass&);

			/* copy assignment operator */
			pass& operator=(const pass&);

			// -- M E M B E R S --------------------------
			// const irc::data&			_data;
			// const irc::connection&	_conn;
			// std::string				_password;

	};

}

#endif
