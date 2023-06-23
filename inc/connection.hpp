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

namespace irc {


	// -- C O N N E C T I O N -------------------------------------------------

    class connection {


        public:

			// -- public constructors -----------------------------------------

			/* pollfd reference constructor */
            connection(struct pollfd&);

			/* copy constructor */
			connection(const connection& conn);

			/* destructor */
			~connection(void);

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
            const struct pollfd& getpfd(void) const;
            int getfd(void) const;
            short getevents(void) const;
            short getrevents(void) const;

            const std::string&  getnick(void) const;
            const std::string&  getuser(void) const;
            const std::string&  getmsg(void) const;
            const std::string&  getbuffer(void) const;

            void  setnick(const std::string& str);
            void  setuser(const std::string& str);
            void  setmsg(const std::string& str);

			/* copy assignment operator */
			connection& operator=(const connection& other);

			/* == operator */
			bool operator==(const connection& other) const;

        private:

			bool check_crlf(void);

			enum { BUFFER_SIZE = 1024 };

            struct pollfd&   		_pfd;
			std::string             _buffer;
			std::string             _msg;
            std::string             _nick;
            std::string             _user;

    };
}

#endif



