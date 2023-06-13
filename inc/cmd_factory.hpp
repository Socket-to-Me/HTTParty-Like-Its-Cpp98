#ifndef CMD_FACTORY_HEADER
#define CMD_FACTORY_HEADER

#include "cmd.hpp"
#include "join.hpp"
#include "auto_ptr.hpp"

#include <string>
#include <unordered_set>
#include <map>


// -- I R C  N A M E S P A C E ------------------------------------------------

namespace IRC {


	// -- C M D  F A C T O R Y  C L A S S ------------------------------------

	class cmd_factory {

		public:

			// -- T Y P E S ---------------------------------------------------

			/* command pointer */
			typedef auto_ptr<cmd> cmd_ptr;



			// -- F A C T O R Y  M E T H O D S ---------------------------------

			/* create command */
			cmd_ptr search(const std::string& cmd);

			/* get instance */
			static cmd_factory& instance(void);



		private:

			// -- P R I V A T E  T Y P E S ------------------------------------

			/* new command prototype */
			typedef cmd_ptr (*new_cmd)(void);


			// -- S T A T I C  M E M B E R S ----------------------------------

			/* instance */
			static cmd_factory _instance;



			// -- M E M B E R S -----------------------------------------------

			/* command set */
			std::map<std::string, new_cmd> _cmds;


			// -- N O N  I N S T A N T I A B L E  C L A S S -------------------

			/* default constructor */
			cmd_factory(void);

			/* copy constructor */
			cmd_factory(const cmd_factory&);

			/* destructor */
			~cmd_factory(void);

			/* copy assignment operator */
			cmd_factory& operator=(const cmd_factory&);


	};


}


#endif
