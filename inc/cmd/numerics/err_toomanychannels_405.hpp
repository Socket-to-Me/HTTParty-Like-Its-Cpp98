
#ifndef ERR_TOOMANYCHANNELS_405.HPP
# define ERR_TOOMANYCHANNELS_405.HPP

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	// -- C M D  B A S E  C L A S S -------------------------------------------

	class err_toomanychannels_405 {

		public:

			// -- C O N S T R U C T O R S -------------------------------------

			/* default constructor */
			err_toomanychannels_405(void);

			/* destructor */
			virtual ~err_toomanychannels_405(void);


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
			err_toomanychannels_405(const err_toomanychannels_405&);

			/* copy assignment operator */
			err_toomanychannels_405& operator=(const err_toomanychannels_405&);

	};

}

#endif
