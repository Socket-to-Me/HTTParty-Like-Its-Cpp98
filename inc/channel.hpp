#ifndef CHANNEL_HEADER
# define CHANNEL_HEADER

# include <string>
# include <vector>
# include "connection.hpp"

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {


	// -- C O N N E C T I O N -------------------------------------------------

    class channel {


        public:

			// -- public constructors -----------------------------------------

			/* parametric constructor */
            channel(const std::string& name, const std::string& topic);

			/* copy constructor */
			channel(const channel&);

			/* destructor */
			~channel(void);

			// -- public accessors --------------------------------------------
            const std::string&  getname(void) const;
            const std::string&  gettopic(void) const;
            const std::string&  getmode(void) const;
            const std::string&  getkey(void) const;

			// -- public methods ----------------------------------------------
            void  setname(const irc::connection& op, const std::string& str);
            void  settopic(const irc::connection& op, const std::string& str);
            void  setmode(const irc::connection& op, const std::string& str);
            void  setkey(const irc::connection& op, const std::string& str);

			void kick(const irc::connection& op, const irc::connection& conn);
			void invite(const irc::connection& op, const irc::connection& conn);
			void giveOperatorPrivilege(const irc::connection& op, const irc::connection& conn);
			void takeOperatorPrivilege(const irc::connection& op, const irc::connection& conn);

		private:

			/* default constructor */
            channel(void);

			// -- private assignment operator ----------------------------------

			/* copy assignment operator */
			channel& operator=(const channel&);

			// -- private members --------------------------------------------
			std::string				_name;
			std::string				_topic;
			std::string				_mode;
			std::string				_key;
			std::vector<irc::connection>	_operators;
			std::vector<irc::connection>	_connections;

    };
}

#endif
