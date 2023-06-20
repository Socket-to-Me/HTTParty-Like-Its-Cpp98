#include "socket.hpp"


// -- P U B L I C  C O N S T R U C T O R S ------------------------------------

/* default constructor */
irc::Socket::Socket(void)
: _descriptor(NULL_DESCRIPTOR), _count(NULL) {
	// code here...
}

/* copy constructor */
irc::Socket::Socket(const Socket& other)
: _descriptor(other._descriptor), _count(other._count) {
	// check count validity
	if (_count) {
		// increment number of references
		++(*_count);
	}
}

/* destructor */
irc::Socket::~Socket(void) {
	// check socket end of life
	if (_count && (--(*_count) == 0)) {
		// check descriptor validity
		if (_descriptor != NULL_DESCRIPTOR) {
			// close socket
			::close(_descriptor);
			// invalidate descriptor
			_descriptor = NULL_DESCRIPTOR;
		} // deallocate count
		delete _count;
		// invalidate count
		_count = NULL;
	}
}


// -- P U B L I C  O P E R A T O R S ------------------------------------------

/* copy assignment operator */
irc::Socket& irc::Socket::operator=(const Socket& socket) {
	// check self assignment
	if (this != &socket) {
		// call destructor
		this->~Socket();
		// copy descriptor
		_descriptor = socket._descriptor;
		_count      = socket._count;
		// check count validity
		if (_count) {
			// increment number of references
			++(*_count); }
	} // return self reference
	return *this;
}

/* bool operator */
irc::Socket::operator bool(void) const {
	// check descriptor validity
	return _descriptor != NULL_DESCRIPTOR;
}

/* not operator */
bool irc::Socket::operator!(void) const {
	// check descriptor validity
	return _descriptor == NULL_DESCRIPTOR;
}

/* equality operator */
bool irc::Socket::operator==(const Socket& socket) const {
	// check descriptors equality
	return _descriptor == socket._descriptor;
}

/* inequality operator */
bool irc::Socket::operator!=(const Socket& socket) const {
	// check descriptors inequality
	return (_descriptor != socket._descriptor);
}

/* dereference operator */
irc::Socket::Descriptor irc::Socket::operator*(void) const {
	// return descriptor
	return _descriptor;
}


// -- P U B L I C  M E T H O D S ----------------------------------------------

