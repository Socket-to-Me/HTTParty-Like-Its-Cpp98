#ifndef SOCKADDR_HEADER
#define SOCKADDR_HEADER

#include "socket.hpp"

#include <string>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// -- I R C  N A M E S P A C E ------------------------------------------------

namespace IRC {

	// -- S O C K A D D R  C L A S S ------------------------------------------

	class SockAddr {


		public:
			// -- P R I V A T E  A L I A S E S --------------------------------

			/* addr_in type */
			typedef struct sockaddr_in SockAddrIn;

			/* family type */
			typedef sa_family_t Family;

			/* port type */
			typedef uint16_t Port;

			/* ip type */
			typedef std::string Ip;

			/* addr type */
			typedef unsigned long Addr;

			/* self type */
			typedef SockAddr Self;

			/* host type */
			typedef struct hostent Host;

		private:

			// -- P R I V A T E  M E M B E R S --------------------------------

			/* family */
			Family _family;

			/* port */
			Port _port;

			/* ip */
			Ip _ip;


		public:

			/* default constructor */
			SockAddr(void);

			/* copy constructor */
			SockAddr(const Self& other);

			/* field constructor */
			SockAddr(const Family& family, const Port& port, const Ip& = "");

			/* destructor */
			~SockAddr(void);


			// -- P U B L I C  A S S I G N M E N T  O P E R A T O R S ---------

			/* copy assignment operator */
			SockAddr& operator=(const Self& other);


			// -- P U B L I C  A C C E S S O R S ------------------------------

			/* family accessor */
			const Family& family(void) const;

			/* port accessor */
			const Port& port(void) const;

			/* ip accessor */
			const Ip& ip(void) const;


			// -- P U B L I C  C O N V E R S I O N ----------------------------

			/* conversion to addr_in */
			SockAddrIn to_sockaddr_in(void) const;

	};


	int bind(const Socket& socket, const SockAddr& addr);

}

#endif
