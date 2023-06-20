#include "sockaddr.hpp"

// -- S O C K A D D R  C L A S S ----------------------------------------------

/* default constructor */
irc::SockAddr::SockAddr(void)
:	_family(0),
	_port(0),
	_ip("") {
	// code here...
}

/* copy constructor */
irc::SockAddr::SockAddr(const Self& other)
:	_family(other._family),
	_port(other._port),
	_ip(other._ip) {
	// code here...
}

/* field constructor */
irc::SockAddr::SockAddr(const Family& family, const Port& port, const Ip& ip)
:	_family(family),
	_port(htons(port)),
	_ip(ip) {
	// code here...
}

/* destructor */
irc::SockAddr::~SockAddr(void) {
	// code here...
}


// -- P U B L I C  A S S I G N M E N T  O P E R A T O R S ---------------------

/* copy assignment operator */
irc::SockAddr& irc::SockAddr::operator=(const Self& other) {
	// check for self-assignment
	if (this != &other) {
		// assign private members
		_family = other._family;
		_port   = other._port;
		_ip     = other._ip;
	} // return self reference
	return *this;
}


// -- P U B L I C  A C C E S S O R S ------------------------------------------

/* family accessor */
const irc::SockAddr::Family& irc::SockAddr::family(void) const {
	return _family;
}

/* port accessor */
const irc::SockAddr::Port& irc::SockAddr::port(void) const {
	return _port;
}

/* ip accessor */
const irc::SockAddr::Ip& irc::SockAddr::ip(void) const {
	return _ip;
}


// -- P U B L I C  C O N V E R S I O N ----------------------------------------

/* conversion to addr_in */
irc::SockAddr::SockAddrIn irc::SockAddr::to_sockaddr_in(void) const {

	// instantiate SockAddrIn structure
	SockAddrIn addr_in;

	// assign private members
	addr_in.sin_family = _family;
	addr_in.sin_port   = _port;

	if (_ip.empty()) {
		std::cout << "INADDR_ANY: " << INADDR_ANY << std::endl;
		addr_in.sin_addr.s_addr = htonl(INADDR_ANY);
		return addr_in;
	}

	// get host by name
	Host* host = gethostbyname(_ip.c_str());
	if (!host) {
		std::cerr << "gethostbyname() failed" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "string: " << _ip << std::endl;
	std::cout << "host: " << host->h_name << std::endl;
	std::cout << "addr: " << inet_ntoa(*reinterpret_cast<struct in_addr*>(host->h_addr)) << std::endl;

	// assign host address
	addr_in.sin_addr   = *reinterpret_cast<struct in_addr*>(host->h_addr);

	// do i need to free host?


	// return addr_in
	return addr_in;
}


// -- B I N D  F U N C T I O N ------------------------------------------------

/* bind function */
int irc::bind(const Socket& socket, const SockAddr& addr) {
	// check for invalid socket
	if (socket) {
		// convert SockAddr to SockAddrIn structure
		const irc::SockAddr::SockAddrIn addr_in = addr.to_sockaddr_in();
		std::cout << "trying to bind to: " << inet_ntoa(addr_in.sin_addr) << std::endl;
		// bind socket to addr
		return ::bind(*socket,
				reinterpret_cast<const struct sockaddr*>(&addr_in),
				sizeof(addr_in));
	}
	// return error
	return -1;
}





