#ifndef ALIVE_HEADER
# define ALIVE_HEADER

# include <ctime>
# include <string>
# include <sys/socket.h>


// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {


	// -- A L I V E -----------------------------------------------------------

	// this class handles ping and pong messages, to check if the connection is still alive

	class alive {


		public:

			// -- public constructors -----------------------------------------

			/* connection constructor */
			alive(const int fd);

			/* copy constructor */
			alive(const alive& other);

			/* destructor */
			~alive(void);


			// -- public assignment operators ---------------------------------

			/* copy assignment operator */
			alive& operator=(const alive& other);

			void set_server_name(const std::string& server_name);


			// -- public methods ----------------------------------------------

			/* check if connection is alive */
			bool is_alive(void);

			/* pong received */
			void pong(void);


		private:

			// -- private members ---------------------------------------------

			/* connection reference */
			int _fd;

			/* server name */
			std::string _server_name;

			/* waiting for pong flag */
			bool _wait_pong;

			/* last ping time */
			time_t _last_ping;

	};

}

#endif
