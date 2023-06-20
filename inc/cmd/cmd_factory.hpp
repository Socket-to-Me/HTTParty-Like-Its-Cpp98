#ifndef CMD_FACTORY_HEADER
#define CMD_FACTORY_HEADER

#include "cmd.hpp"
#include "join.hpp"
#include "auto_ptr.hpp"

#include <string>
#include <map>

#include "invite.hpp"
#include "join.hpp"
#include "kick.hpp"
#include "list.hpp"
#include "mode.hpp"
#include "nick.hpp"
#include "part.hpp"
#include "pass.hpp"
#include "ping.hpp"
#include "privmsg.hpp"
#include "quit.hpp"
#include "topic.hpp"
#include "user.hpp"
#include <vector>

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {


	// -- C M D  F A C T O R Y  C L A S S ------------------------------------

	class cmd_factory {

		public:

			// -- T Y P E S ---------------------------------------------------

			/* command pointer */
			typedef irc::auto_ptr<irc::cmd> cmd_ptr;

			/* new command prototype */ // method create proto !!!
			typedef cmd_ptr (*cmd_maker)(std::vector<irc::token>);



			// -- F A C T O R Y  M E T H O D S ---------------------------------

			/* create command */
			static cmd_maker search(const std::string& cmd);

			



		private:

			// -- P R I V A T E  T Y P E S ------------------------------------

			


			// -- S T A T I C  M E M B E R S ----------------------------------

		



			// -- M E M B E R S -----------------------------------------------

			/* command set */
			static std::map<std::string, cmd_maker> _cmds;


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
