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
# include "cmd_factory.hpp"
# include "parser.hpp"
# include "cmd.hpp"
# include "connection.hpp"
# include "socket.hpp"
# include "channel.hpp"
# include "numerics.hpp"
#include "output.hpp"
#include "logo.hpp"
#include "log.hpp"


// -- N A M E S P A C E  I R C ------------------------------------------------

namespace irc {


	// -- S E R V E R ---------------------------------------------------------

	class server {


		public:

			// -- public methods ----------------------------------------------

			/* start server */
			void start(const std::string&, int);

			/* stop server */
			void stop(void);

			/* send message to a client */
			void send(irc::connection&, const std::string&);


			// -- C O M M A N D  U T I L S ---------------------

			// bool	isConnRegistered(const irc::connection& conn) const;
			void newChannel(const std::string&);
			bool isNickInUse(const std::string&) const;
			bool isChannelExist(const std::string&) const;

			// -- G E T T E R S ---------------------

			irc::channel& getchannel(const std::string&);
			irc::connection&	getconnection(const std::string& nick);

			const std::string&	getname(void) const;
			const std::string&	getversion(void) const;
			const std::string&	getusermodes(void) const;
			const std::string&	getchannelmodes(void) const;
			std::string			getcreation(void) const;



			// -- public static methods ---------------------------------------

			/* get singleton instance */
			static server&	instance(void);


		private:

			// -- private types -----------------------------------------------

			/* pollfd type */
			typedef struct pollfd	pollfd;

			/* connection map type */
			typedef std::map<std::string, irc::connection> connection_map;

			/* channel map type */
			typedef std::map<std::string, irc::channel> channel_map;

			/* pollfd vector type */
			typedef std::vector<pollfd> pollfd_vector;


			// -- private constructors ----------------------------------------

			/* default constructor */
			server(void);

			/* destructor */
			~server(void);


			// -- private static members --------------------------------------

			/* singleton instance */
			static server _instance;


			// -- private members ---------------------------------------------

			/* server socket */
			int	_socket;

			/* server running flag */
			bool _is_running;

			/* pollfds */
			pollfd_vector _pollfds;

			/* connection map */ // [nick, connection]
			connection_map _connections;

			/* channel map */ // [name, channel]
			channel_map _channels;

			/* network name */
			const std::string _networkname;

			/* version */
			const std::string _version;

			/* user modes */
			const std::string _usermodes;

			/* channel modes */
			const std::string _channelmodes;

			/* channel modes with params */
			const std::string _channelmodeswithparams;

			/* creation time */
			const std::time_t _creation;


			// -- private methods ---------------------------------------------

			/* setup server socket */
			int setupSocket(const std::string&, int);

			/* add new pollfd */
			void add_pollfd(const int);

			/* remove pollfd */
			void remove_pollfd(const int);

			/* accept new connection */
			void accept_new_connection(void);

			/* handle active connections */
			void handle_active_connections(void);

	};


	/* struct pollfd {
	 *     int fd;         // File descriptor to monitor
	 *     short events;   // Events to monitor (input/output/error events)
	 *     short revents;  // Events that occurred (filled by the kernel)
	 * };
	 */

}

#endif
