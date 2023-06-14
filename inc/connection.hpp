#ifndef CONNECTION_HEADER
#define CONNECTION_HEADER

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <vector>
#include <poll.h>


// -- I R C  N A M E S P A C E ------------------------------------------------

namespace IRC {


	// -- C O N N E C T I O N -------------------------------------------------

    class Connection {


        public:

			// -- public constructors -----------------------------------------

			/* pollfd reference constructor */
            Connection(const struct pollfd&);

			/* copy constructor */
			Connection(const Connection&);

			/* destructor */
			~Connection(void);


		private:

			// -- private assignment operator ----------------------------------

			/* copy assignment operator */
			Connection& operator=(const Connection&);


		public:

			// -- public methods ----------------------------------------------

			/* receive bytes */
            bool receive(void);

			/* send bytes */
            ssize_t send(const std::string& message);

			/* close connection */
            void close(void);

			/* extract message */
			std::string extract_message(void);


			// -- public accessors --------------------------------------------

			/* get file descriptor */
            int getfd(void);


        private:

			// -- private methods ---------------------------------------------

			/* check end of message */
			bool check_crlf(void);


			// -- private enums -----------------------------------------------

			/* buffer size */
			enum { BUFFER_SIZE = 1024 };


			// -- private members ---------------------------------------------

			/* pollfd reference */
            const struct pollfd& _pfd;

			/* buffer */
			std::string _buffer;


    };

}

#endif



