#ifndef SERVER_HEADER
# define SERVER_HEADER

# include <algorithm>
# include <vector>
# include <queue>
# include <map>
# include <string>
# include <cstdlib>
# include <poll.h>
# include <iostream>
# include <ctime>

//#include "msg.hpp"
# include "time.hpp"
# include "cmd_factory.hpp"
# include "parser.hpp"
# include "cmd.hpp"
# include "connection.hpp"
# include "socket.hpp"
# include "channel.hpp"
# include "numerics.hpp"
# include "output.hpp"
# include "logo.hpp"
# include "log.hpp"


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

			/* send message to all clients */
			bool broadcast(const std::string&);

			// -- public methods ----------------------------------------------

			// bool	isConnRegistered(const irc::connection& conn) const;
			void newChannel(const std::string&);
			bool isNickInUse(const std::string&) const;
			bool isChannelExist(const std::string&) const;
			bool isChannelNameValid(const std::string& name) const;

			/* unsubscribe client connection */
			void unsubscribe(irc::connection&);

			/* add to remove queue */
			void add_to_remove_queue(irc::connection&);

			/* leave all channels */
			void leave_all_channels(irc::connection&);

			// -- public accessors --------------------------------------------

			/* get channels */
			std::map<std::string, irc::channel>& getchannels(void);

			/* get channel */
			irc::channel& getchannel(const std::string&);

			/* get connection */
			irc::connection& getconnection(const std::string& nick);

			/* get server name */
			const std::string& getname(void) const;

			/* get server version */
			const std::string&	getversion(void) const;

			/* get server user modes */
			const std::string& getusermodes(void) const;

			/* get server channel modes */
			const std::string& getchannelmodes(void) const;

			/* get server creation time */
			const std::string& getcreation(void) const;



			// -- public static methods ---------------------------------------

			/* get singleton instance */
			static server& instance(void);


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

			/* remove queue */
			std::queue<irc::connection*> _remove_queue;

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
			const std::string _creation;


			// -- private methods ---------------------------------------------

			/* setup server socket */
			int setupSocket(const std::string&, int);

			/* setup client socket */
			int setup_client_socket(void) const;

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
