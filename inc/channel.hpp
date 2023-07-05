#ifndef CHANNEL_HEADER
# define CHANNEL_HEADER

# include <sstream>
# include <iterator>
# include <string>
# include <vector>
# include <unordered_set>

# include "connection.hpp"


// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {


	// -- C H A N N E L -------------------------------------------------------

    class channel {


        public:

			// -- public constructors -----------------------------------------

			/* parametric constructor */
            channel(const std::string& name);

			/* copy constructor */
			channel(const channel& other);

			/* destructor */
			~channel(void);

			// -- public accessors --------------------------------------------
            const std::string&  getname(void) const;
            const std::string&  gettopic(void) const;
            const std::string  	getmode(void) const;
            const std::vector<irc::connection*>&  getoperators(void) const;
            const std::vector<irc::connection*>&  getconnections(void) const;

            std::string  	getconnectionsasstr(void) const;
            bool  			checkPassword(const std::string& password) const;

			// -- public methods ----------------------------------------------
            void  setname(const irc::connection& op, const std::string& str);
            void  settopic(const irc::connection& op, const std::string& str);
            void  setmode(const irc::connection& op, const std::string& str);
            void  setkey(const irc::connection& op, const std::string& str);

			void addOperator(irc::connection& conn);
			void addUser(irc::connection& conn);
			void removeUser(irc::connection& conn);
			void removeOperator(irc::connection& conn);

			void kick(const irc::connection& op, irc::connection& conn);
			void invite(const irc::connection& op, irc::connection& conn);
			void giveOperatorPrivilege(const irc::connection& op, irc::connection& conn);
			void takeOperatorPrivilege(const irc::connection& op, irc::connection& conn);

			bool broadcast(const std::string& msg);
			bool send(const std::string& nick, const std::string& msg);

			bool isConnection(const irc::connection& conn) const;
			bool isOperator(const irc::connection& op) const;

			void set_mode_channel_key(bool val);
			bool is_mode_channel_key(void);

			std::string getsymbol(void) const;

		private:

			// -- private methods ----------------------------------------------
            const std::string&  getkey(void) const;

			/* default constructor */
            channel(void);

			// -- private assignment operator ----------------------------------

			/* copy assignment operator */
			channel& operator=(const channel&);

			// -- private members --------------------------------------------
			std::string						_name;
			std::string						_topic;
			std::string						_key;
			std::vector<irc::connection*>	_operators;
			std::vector<irc::connection*>	_connections;

			// -- modes -----------------------------------------------------

			// +i (Invite-only): When this mode is set, only invited clients can join the channel. Other clients cannot join without an invitation.
			bool	_mode_invite_only;

			// +t (Topic restricted): With this mode set, only channel operators can change the topic of the channel. Regular clients are not allowed to modify the channel's topic.
			bool	_mode_topic_restricted;

			// +l (User limit): This mode allows setting a limit on the number of clients that can join the channel simultaneously. Once the limit is reached, other clients attempting to join will be denied access until there is an available slot.
			bool	_mode_user_limit;

			// +k (Channel key): This mode enables setting a password or key that clients must provide to join the channel. Clients without the correct key will be unable to enter.
			bool	_mode_channel_key;

			// +o (Operator privileges): This mode grants operator privileges to specific clients. Operators have elevated permissions and can perform certain administrative actions within the channel, such as kicking or banning clients.
			bool	_mode_operator_privileges;

			// +b (Ban): The ban mode allows channel operators to ban specific clients from the channel. Banned clients are prevented from joining the channel until the ban is lifted.
			bool	_mode_ban;

    };
}

#endif
