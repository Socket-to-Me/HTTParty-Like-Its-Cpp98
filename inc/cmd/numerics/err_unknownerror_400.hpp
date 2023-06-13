
#ifndef ERR_UNKNOWNERROR_400.HPP
# define ERR_UNKNOWNERROR_400.HPP

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	// -- C M D  B A S E  C L A S S -------------------------------------------

	class err_unknownerror_400 {

		public:

			// -- C O N S T R U C T O R S -------------------------------------

			/* default constructor */
			err_unknownerror_400(void);

			/* destructor */
			virtual ~err_unknownerror_400(void);


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
			err_unknownerror_400(const err_unknownerror_400&);

			/* copy assignment operator */
			err_unknownerror_400& operator=(const err_unknownerror_400&);

	};

}

#endif
