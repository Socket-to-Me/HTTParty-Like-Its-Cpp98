
#ifndef RPL_WHOISSECURE_671.HPP
# define RPL_WHOISSECURE_671.HPP

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	// -- C M D  B A S E  C L A S S -------------------------------------------

	class rpl_whoissecure_671 {

		public:

			// -- C O N S T R U C T O R S -------------------------------------

			/* default constructor */
			rpl_whoissecure_671(void);

			/* destructor */
			virtual ~rpl_whoissecure_671(void);


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
			rpl_whoissecure_671(const rpl_whoissecure_671&);

			/* copy assignment operator */
			rpl_whoissecure_671& operator=(const rpl_whoissecure_671&);

	};

}

#endif
