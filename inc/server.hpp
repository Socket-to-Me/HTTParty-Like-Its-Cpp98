#ifndef SERVER_HEADER
#define SERVER_HEADER

#include <vector>
#include <string>

#include "connection.hpp"
#include "socket.hpp"

// -- N A M E S P A C E  I R C ------------------------------------------------

namespace IRC {

	// -- S E R V E R  C L A S S ----------------------------------------------

	class Server {

		public:

			// -- P U B L I C  M E T H O D S ----------------------------------

			/* start server */
			bool	start(const std::string& ip, int port);

			/* accept connections */
			void	acceptConnections(void);

			/* stop server */
			void	stop(void);

			/* restart server */
			void	restart(void);

			/* subscribe client */
			void	subscribe(const IRC::Connection& conn);

			/* unsubscribe client */
			void	unsubscribe(const IRC::Connection& conn);

			/* send message to all clients */
			void	broadcast(const std::string& msg);


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

			/* server clients */
			// std::vector<Client> _client;
			std::vector<IRC::Connection> _conns;

			/* server socket */
			// TODO = change to socket object
			int	_socket;

			// -- P R I V A T E  M E T H O D S ----------------------------------

			void	handleNewConnection(IRC::Connection& connection);


	};

}

#endif
