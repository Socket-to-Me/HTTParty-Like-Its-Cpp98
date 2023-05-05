#ifndef SOCKETS_HEADER
#define SOCKETS_HEADER

#include <sys/socket.h>
#include <unistd.h>

/* prototype */
// int socket(int domain, int type, int protocol);

// DESCRIPTION socket() creates an endpoint for communication and returns a descriptor.


/* protocol */

// PF_LOCAL        Host-internal protocols, formerly called PF_UNIX,
// PF_UNIX         Host-internal protocols, deprecated, use PF_LOCAL,
// PF_INET         Internet version 4 protocols,
// PF_ROUTE        Internal Routing protocol,
// PF_KEY          Internal key-management function,
// PF_INET6        Internet version 6 protocols,
// PF_SYSTEM       System domain,
// PF_NDRV         Raw access to network device,
// PF_VSOCK        VM Sockets protocols


/* type */

// SOCK_STREAM
// SOCK_DGRAM
// SOCK_RAW

// -- N A M E S P A C E S  I R C ----------------------------------------------

namespace IRC {


	// -- S O C K E T  C L A S S ----------------------------------------------

	class Socket {

		public:

			// -- P U B L I C  A L I A S E S ----------------------------------

			/* descriptor type */
			typedef int Descriptor;


			// -- P U B L I C  C O N S T R U C T O R S ------------------------

			/* default constructor */
			Socket(void);

			/* copy constructor */
			Socket(const Socket &socket);

			/* destructor */
			~Socket(void);


			// -- P U B L I C  M E T H O D S ----------------------------------

			/* create socket */
			void create(int domain, int type, int protocol);


		private:

			// -- P R I V A T E  E N U M S ------------------------------------

			/* descriptor type */
			enum {
				NULL_DESCRIPTOR = -1
			};

			// -- P R I V A T E  M E M B E R S --------------------------------

			/* descriptor */
			mutable Descriptor _descriptor;


	};

}

#endif
