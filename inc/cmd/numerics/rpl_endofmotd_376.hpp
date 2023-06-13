
#ifndef RPL_ENDOFMOTD_376.HPP
# define RPL_ENDOFMOTD_376.HPP

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	// -- C M D  B A S E  C L A S S -------------------------------------------

	class rpl_endofmotd_376 {

		public:

			// -- C O N S T R U C T O R S -------------------------------------

			/* default constructor */
			rpl_endofmotd_376(void);

			/* destructor */
			virtual ~rpl_endofmotd_376(void);


			// -- V I R T U A L  M E T H O D S --------------------------------

			/* execute command */
			virtual bool execute(void) = 0;

			/* evaluate command */
			virtual bool evaluate(void) = 0;

            /* create command */
            irc::auto_ptr<irc::cmd> create(void);

		private:

			// -- N O N - C O P Y A B L E  C L A S S --------------------------

			/* copy constructor */
			rpl_endofmotd_376(const rpl_endofmotd_376&);

			/* copy assignment operator */
			rpl_endofmotd_376& operator=(const rpl_endofmotd_376&);

	};

}

#endif
