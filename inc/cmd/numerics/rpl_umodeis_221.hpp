
#ifndef RPL_UMODEIS_221.HPP
# define RPL_UMODEIS_221.HPP

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	// -- C M D  B A S E  C L A S S -------------------------------------------

	class rpl_umodeis_221 {

		public:

			// -- C O N S T R U C T O R S -------------------------------------

			/* default constructor */
			rpl_umodeis_221(void);

			/* destructor */
			virtual ~rpl_umodeis_221(void);


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
			rpl_umodeis_221(const rpl_umodeis_221&);

			/* copy assignment operator */
			rpl_umodeis_221& operator=(const rpl_umodeis_221&);

	};

}

#endif
