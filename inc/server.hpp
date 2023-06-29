#ifndef SERVER_HEADER
# define SERVER_HEADER

# include <algorithm>
# include <vector>
# include <map>
# include <string>
# include <cstdlib>
# include <poll.h>
# include <iostream>
# include <ctime>

//#include "msg.hpp"
#include "cmd_factory.hpp"
# include "parser.hpp"
# include "cmd.hpp"
# include "connection.hpp"
# include "socket.hpp"
# include "channel.hpp"
# include "numerics.hpp"
#include "output.hpp"


// -- N A M E S P A C E  I R C ------------------------------------------------

namespace irc {

	// -- S E R V E R  C L A S S ----------------------------------------------

	class server {

		public:

			// -- P U B L I C  M E T H O D S ----------------------------------

			/* start server */
			void	start(const std::string& ip, int port);

			/* stop server */
			void	stop(void);

			/* restart server */
			void	restart(void);

			/* subscribe client */
			void	subscribe(const irc::connection& conn);

			/* unsubscribe client */
			void	unsubscribe(const irc::connection& conn);

			/* send message to all clients */
			void	broadcast(const std::string& msg);

			/* send message to a client */
			void	send(irc::connection& conn, const std::string& message);

			// -- C O M M A N D  U T I L S ---------------------

			// bool	isConnRegistered(const irc::connection& conn) const;
			bool	isNickInUse(const std::string& nick) const;
			bool	isChannelExist(const std::string& channel) const;

			// -- G E T T E R S ---------------------

			irc::channel&	getchannel(const std::string& channel);

			const std::string&	getname(void) const;
			const std::string&	getversion(void) const;
			const std::string&	getusermodes(void) const;
			const std::string&	getchannelmodes(void) const;
			std::string	getcreation(void) const;

			// -- P U B L I C  S T A T I C  M E T H O D S ---------------------

			/* get singleton instance */
			static server&	instance(void);


		private:

			// -- P R I V A T E  C O N S T R U C T O R S ----------------------

			/* default constructor */
			server(void);

			/* destructor */
			~server(void);

			// -- P R I V A T E  S T A T I C  M E M B E R S -------------------

			/* singleton instance */
			static server	_instance;

			// -- P R I V A T E  M E M B E R S --------------------------------

			/* server socket */
			// TODO = change to socket object
			int	_socket;

			bool _is_running;

			// struct pollfd {
			//     int fd;         // File descriptor to monitor
			//     short events;   // Events to monitor (input/output/error events)
			//     short revents;  // Events that occurred (filled by the kernel)
			// };

			std::vector<struct pollfd>				_pollfds;

			std::map<std::string, irc::connection>	_connections;	// NICK as key
			std::map<std::string, irc::channel>		_channels;		// name as key

			const std::string		_networkname;
			const std::string		_version;
			const std::string		_usermodes;
			const std::string		_channelmodes;
			const std::string		_channelmodeswithparams;
			const std::time_t		_creation;

			// -- P R I V A T E  M E T H O D S ----------------------------------

			void setupSocket(const std::string& ip, int port);
			void addPollfd(int fd);
			void accept_new_connection(void);
			void handle_active_connections(void);

	};

}

#endif
