#ifndef CONNECTION_HEADER
# define CONNECTION_HEADER

# include <iostream>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <cstring>
# include <vector>
# include <poll.h>
# include <errno.h>
# include "alive.hpp"


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


			// -- public assignment operators ---------------------------------

			/* copy assignment operator */
			connection& operator=(const connection& other);


			// -- public comparison operators ---------------------------------

			/* equality operator */
			bool operator==(const connection& other) const;


			// -- public methods ----------------------------------------------

			/* receive bytes */
            bool receive(void);

			/* read bytes after new connection */
			bool read(void);

			/* send bytes */
            ssize_t send(const std::string& message) const;

			/* close connection */
            void close(void);

			/* extract message */
			std::string extract_message(void);

			/* init alive */
			void init_alive(const std::string&);

			/* pong */
			void pong(void);


			// -- public accessors --------------------------------------------

			/* get pollfd */
            const struct pollfd& getpfd(void) const;

			/* get file descriptor */
            int getfd(void) const;

			/* get events */
            short getevents(void) const;

			/* get revents */
            short getrevents(void) const;

			/* get nick */
            const std::string&  getnick(void) const;

			/* get user */
            const std::string&  getuser(void) const;

			/* get message */
            const std::string&  getmsg(void) const;

			/* get buffer */
            const std::string&  getbuffer(void) const;

			/* get password */
            const std::string&  getpassword(void) const;

			/* get channel name */
            const std::string&  getchannelname(void) const;
            const std::string&  gettarget(void) const;

			/* is registered */
			bool is_registered(void) const;

			/* is alive */
			bool is_alive(void);


			// -- public setters ----------------------------------------------

			/* set nick */
            void  setnick(const std::string& str);

			/* set user */
            void  setuser(const std::string& str);

			/* set message */
            void  setmsg(const std::string& str);

			/* set password */
            void  setpassword(const std::string& str);

			/* set channel name */
            void  setchannelname(const std::string& str);
            void  settarget(const std::string& str);

			/* register client */
			void register_client(void);



        private:

			// -- private methods ---------------------------------------------

			/* check for CRLF */
			bool check_crlf(void);


			// -- private enumerations ----------------------------------------

			/* buffer size */
			enum { BUFFER_SIZE = 1024 };


			// -- private members ---------------------------------------------

			/* pollfd */
            struct pollfd& _pfd;

			/* buffer */
			std::string _buffer;

			/* message */
			std::string _msg;

			/* nick */
            std::string _nick;

			/* user */
            std::string _user;

			/* password */
            std::string _password;

			/* channel name */
            std::string _channelname;

			/* target */
            std::string _target;

			/* registered */
			bool _registered;

			/* alive */
			irc::alive _alive;

    };
}

#endif



