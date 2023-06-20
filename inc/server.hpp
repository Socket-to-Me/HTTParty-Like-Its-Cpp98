#ifndef SERVER_HEADER
# define SERVER_HEADER


# include <vector>
# include <string>
# include <poll.h>

# include "connection.hpp"
# include "socket.hpp"

// -- N A M E S P A C E  I R C ------------------------------------------------

namespace irc {

	// -- S E R V E R  C L A S S ----------------------------------------------

	class Server {

		public:

			// -- P U B L I C  M E T H O D S ----------------------------------

			/* start server */
			void	start(const std::string& ip, int port);

			/* stop server */
			void	stop(void);

			/* restart server */
			void	restart(void);

			/* subscribe client */
			void	subscribe(const irc::Connection& conn);

			/* unsubscribe client */
			void	unsubscribe(const irc::Connection& conn);

			/* send message to all clients */
			void	broadcast(const std::string& msg);


			void send(irc::Connection& conn, const std::string& message);

			// -- P U B L I C  S T A T I C  M E T H O D S ---------------------

			/* get singleton instance */
			static Server&	instance(void);


		private:

			// -- P R I V A T E  C O N S T R U C T O R S ----------------------

			/* default constructor */
			Server(void);

			/* copy constructor */
			Server(const Server&);

			/* destructor */
			~Server(void);


			// -- P R I V A T E  S T A T I C  M E M B E R S -------------------

			/* singleton instance */
			static Server	_instance;


			// -- P R I V A T E  M E M B E R S --------------------------------

			/* server socket */
			// TODO = change to socket object
			int	_socket;

			// struct pollfd {
			//     int fd;         // File descriptor to monitor
			//     short events;   // Events to monitor (input/output/error events)
			//     short revents;  // Events that occurred (filled by the kernel)
			// };

			std::vector<struct pollfd>		_pollfds;
			std::vector<irc::Connection>	_connections;

			// <networkname>
			static const std::string		_networkname;

			// -- P R I V A T E  M E T H O D S ----------------------------------

			void	setupSocket(const std::string& ip, int port);
			void    addPollfd(int fd);
			void	acceptNewConnection(void);
			void 	handleActiveConnections(void);


	};

}

#endif
