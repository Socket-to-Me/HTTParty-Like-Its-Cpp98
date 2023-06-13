
#ifndef RPL_LIST_322.HPP
# define RPL_LIST_322.HPP

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	// -- C M D  B A S E  C L A S S -------------------------------------------

	class rpl_list_322 {

		public:

			// -- C O N S T R U C T O R S -------------------------------------

			/* default constructor */
			rpl_list_322(void);

			/* destructor */
			virtual ~rpl_list_322(void);


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
			rpl_list_322(const rpl_list_322&);

			/* copy assignment operator */
			rpl_list_322& operator=(const rpl_list_322&);

	};

}

#endif
