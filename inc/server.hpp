#ifndef SERVER_HEADER
#define SERVER_HEADER

#include <vector>



// -- N A M E S P A C E  I R C ------------------------------------------------

namespace IRC {

class Client {public:};

	// -- S E R V E R  C L A S S ----------------------------------------------

	class Server {

		public:

			// -- P U B L I C  M E T H O D S ----------------------------------

			/* start server */
			void start(void);

			/* stop server */
			void stop(void);

			/* restart server */
			void restart(void);

			/* subscribe client */
			void subscribe(const Client& client);

			/* unsubscribe client */
			void unsubscribe(const Client& client);

			/* send message to all clients */
			void broadcast(const std::string& message);


			// -- P U B L I C  S T A T I C  M E T H O D S ---------------------

			/* get singleton instance */
			static Server& instance(void);


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
			static Server _instance;


			// -- P R I V A T E  M E M B E R S --------------------------------

			/* server clients */
			std::vector<Client> _client;



	};

}

#endif
