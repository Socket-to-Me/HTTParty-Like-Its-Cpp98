#ifndef SOCKETS_HEADER
#define SOCKETS_HEADER

#include <sys/socket.h>
#include <unistd.h>
#include <iostream>


// -- N A M E S P A C E S  I R C ----------------------------------------------

namespace irc {


	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };



	// -- D O M A I N  S T R U C T S ------------------------------------------

	// this structs are used to define socket domain type

	/* local domain (also known as unix domain) */
	struct local {
		#ifdef __linux__
			static const int value = AF_LOCAL;
		#elif __APPLE__ || __FreeBSD__
			static const int value = PF_LOCAL;
		#endif
	};

	/* inet domain (also known as ipv4 domain) */
	struct inet {
		#ifdef __linux__
			static const int value = AF_INET;
		#elif __APPLE__ || __MACH__ || __FreeBSD__
			static const int value = PF_INET;
		#endif
	};

	/* inet6 domain (also known as ipv6 domain) */
	struct inet6 {
		#ifdef __linux__
			static const int value = AF_INET6;
		#elif __APPLE__ || __MACH__ || __FreeBSD__
			static const int value = PF_INET6;
		#endif
	};


	// -- D O M A I N  M E T A  U T I L I T Y ---------------------------------

	/* is domain false */
	template <class T>
	struct is_domain {
		static const bool value = false;
	};

	/* is domain true */
	template <>
	struct is_domain<local> {
		static const bool value = true;
	};

	/* is domain true */
	template <>
	struct is_domain<inet> {
		static const bool value = true;
	};

	/* is domain true */
	template <>
	struct is_domain<inet6> {
		static const bool value = true;
	};


	// -- T Y P E  S T R U C T S ----------------------------------------------

	// this structs are used to define socket type type

	/* stream type */
	struct stream   { static const int value = SOCK_STREAM; };

	/* datagram type */
	struct datagram { static const int value = SOCK_DGRAM;  };

	/* raw type */
	struct raw      { static const int value = SOCK_RAW;    };


	// -- T Y P E  M E T A  U T I L I T Y ---------------------------------

	/* is type false */
	template <class T>
	struct is_type {
		static const bool value = false;
	};

	/* is type true */
	template <>
	struct is_type<stream> {
		static const bool value = true;
	};

	/* is type true */
	template <>
	struct is_type<datagram> {
		static const bool value = true;
	};

	/* is type true */
	template <>
	struct is_type<raw> {
		static const bool value = true;
	};





	// -- S O C K E T  C L A S S ----------------------------------------------

	// this class act like shared_ptr but for socket descriptor
	// so if you copy a socket, the descriptor will be shared

	class Socket {

		public:

			// -- P U B L I C  A L I A S E S ----------------------------------

			/* descriptor type */
			typedef int Descriptor;

			/* protocol type */
			typedef int Protocol;

			/* size type */
			typedef std::size_t Size;


			// -- P U B L I C  C O N S T R U C T O R S ------------------------

			/* default constructor */
			Socket(void);

			/* copy constructor */
			Socket(const Socket &socket);

			/* destructor */
			~Socket(void);


			// -- P U B L I C  O P E R A T O R S ------------------------------

			/* copy assignment operator */
			Socket& operator=(const Socket& socket);

			/* bool operator */
			operator bool(void) const;

			/* not operator */
			bool operator!(void) const;

			/* equality operator */
			bool operator==(const Socket &socket) const;

			/* inequality operator */
			bool operator!=(const Socket &socket) const;

			/* dereference operator */
			Descriptor operator*(void) const;



			// -- P U B L I C  M E T H O D S ----------------------------------

			/* create socket */
			template <class D, class T>
			void create(Protocol protocol = 0) {

				// compile time check for domain
				typedef typename irc::enable_if<irc::is_domain<D>::value, D>::type Domain;
				// compile time check for type
				typedef typename irc::enable_if<irc::is_type<T>::value, T>::type Type;

				// call destructor
				this->~Socket();
				// create socket
				_descriptor = ::socket(Domain::value, Type::value, protocol);
				// check descriptor validity
				if (_descriptor != NULL_DESCRIPTOR) {
					// allocate count
					_count = new Size(1);
				}
			}


		private:

			// -- P R I V A T E  E N U M S ------------------------------------

			/* descriptor type */
			enum { NULL_DESCRIPTOR = -1 };

			// -- P R I V A T E  M E M B E R S --------------------------------

			/* descriptor */
			Descriptor _descriptor;

			/* count */
			Size* _count;


	};

}

#endif

/* prototype */
// int socket(int domain, int type, int protocol);

// DESCRIPTION socket() creates an endpoint for communication and returns a descriptor.





/* type */

