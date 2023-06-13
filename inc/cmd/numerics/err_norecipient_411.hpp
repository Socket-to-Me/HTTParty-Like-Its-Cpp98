
#ifndef ERR_NORECIPIENT_411.HPP
# define ERR_NORECIPIENT_411.HPP

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	// -- C M D  B A S E  C L A S S -------------------------------------------

	class err_norecipient_411 {

		public:

			// -- C O N S T R U C T O R S -------------------------------------

			/* default constructor */
			err_norecipient_411(void);

			/* destructor */
			virtual ~err_norecipient_411(void);


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
			err_norecipient_411(const err_norecipient_411&);

			/* copy assignment operator */
			err_norecipient_411& operator=(const err_norecipient_411&);

	};

}

#endif
