#include "socket.hpp"

/* default constructor */
IRC::Socket::Socket(void)
: _descriptor(NULL_DESCRIPTOR) {
	// code here...
}

/* copy constructor */ // INFO: implemented like move constructor
IRC::Socket::Socket(const Socket& other)
: _descriptor(other._descriptor) {
	// invalidate other descriptor
	other._descriptor = NULL_DESCRIPTOR;
	// WARNING: this maybe not be public
	// does socket copy make sense ?
}

/* destructor */
IRC::Socket::~Socket(void) {
	// check descriptor validity
	if (_descriptor != NULL_DESCRIPTOR) {
		// close socket
		::close(_descriptor);
	}
}


/* socket */
void IRC::Socket::create(int domain, int type, int protocol) {
	// check descriptor validity
	if (_descriptor != NULL_DESCRIPTOR) {
		// close socket
		::close(_descriptor);
	}
	// create socket
	_descriptor = ::socket(AF_INET, SOCK_STREAM, 0);
}
