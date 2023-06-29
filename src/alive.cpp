#include "alive.hpp"

#include <iostream>

// -- A L I V E ---------------------------------------------------------------


// -- public constructors -----------------------------------------------------

/* connection constructor */
irc::alive::alive(const int fd)
: _fd(fd),
  _server_name(""),
  _wait_pong(false),
  _last_ping(std::time(0)) {
}

/* copy constructor */
irc::alive::alive(const irc::alive& other)
: _fd(other._fd),
  _server_name(other._server_name),
  _wait_pong(other._wait_pong),
  _last_ping(other._last_ping) {
}

/* destructor */
irc::alive::~alive(void) {
}


// -- public assignment operators ---------------------------------------------

/* copy assignment operator */
irc::alive& irc::alive::operator=(const irc::alive& other) {
	// check for self-assignment
	if (this != &other) {
		// assign members
		_fd = other._fd;
		_server_name = other._server_name;
		_wait_pong = other._wait_pong;
		_last_ping = other._last_ping;
	} // return self-reference
	return *this;
}


void irc::alive::set_server_name(const std::string& server_name) {
	_server_name = server_name;
}

// -- public methods ----------------------------------------------------------

/* check if connection is alive */
bool irc::alive::is_alive(void) {

	// check if waiting for pong
	if (_wait_pong) {
		// check if timeout
		if ((std::time(0) - _last_ping) > 10) {
			// return false
			return false;
		}
	}
	// check if time to ping
	else if ((std::time(0) - _last_ping) > 10) {
		// create ping message
		std::string msg = "PING :" + _server_name + "\r\n";
		// send ping message
		::send(_fd, msg.c_str(), msg.length(), 0);
		irc::log::add_line("[alive] ping sent");
		// update last ping time
		_last_ping = std::time(0);
		// update wait pong flag
		_wait_pong = true;
	}
	// return true
	return true;
}


/* pong received */
void irc::alive::pong(void) {
	_wait_pong = false;
}


