#ifndef CONNECTION_HEADER
# define CONNECTION_HEADER

# include <iostream>
# include <sstream>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <cstring>
# include <vector>
# include <poll.h>
# include <errno.h>
# include "alive.hpp"

# include "log.hpp"


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

			/* check fails */
			bool check_fails(void);

			/* send bytes */
            ssize_t send(const std::string& message) const;

			/* close connection */
            void close(void);

			/* extract message */
			std::string extract_message(void);



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

			/* get host */
            const std::string&  gethost(void) const;

			/* get real name */
            const std::string&  getrealname(void) const;

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

			/* is duplicated */
			bool is_duplicated(void) const;

			/* have pass */
			bool have_pass(void) const;

			/* have nick */
			bool have_nick(void) const;

			/* have user */
			bool have_user(void) const;



			// -- public setters ----------------------------------------------

			/* set nick */
            void  setnick(const std::string& str);

			/* set user */
            void  setuser(const std::string& str);

			/* set host */
            void  sethost(const std::string& str);

			/* set real name */
            void  setrealname(const std::string& str);

			/* set message */
            void  setmsg(const std::string& str);

			/* set password */
            void  setpassword(const std::string& str);

			/* set channel name & target for numerics */
            void  setchannelname(const std::string& str);
            void  settarget(const std::string& str);

			/* register client */
			void register_client(void);

			/* duplicate nick */
			void duplicate_nick(void);

			/* pong */
			void pong(void);

			/* validate pass */
			void validate_pass(void);

			/* validate nick */
			void validate_nick(void);

			/* validate user */
			void validate_user(void);



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

			/* host */
            std::string _host;

			/* real name */
            std::string _realname;

			/* channel name */
            std::string _channelname;

			/* target */
            std::string _target;

			/* registered */
			bool _registered;

			/* duplicated */
			bool _duplicated;

			/* waiting for pong flag */
			bool _wait_pong;

			/* last ping time */
			time_t _last_ping;

			/* alive */
			bool _alive;


			/* have user */
			bool _have_user;

			/* have nick */
			bool _have_nick;

			/* have pass */
			bool _have_pass;

    };
}

#endif



