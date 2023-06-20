#include "connection.hpp"


// -- C O N N E C T I O N -----------------------------------------------------


// -- public constructors -----------------------------------------------------

/* pollfd reference constructor */
irc::Connection::Connection(const struct pollfd& pfd)
: _pfd(pfd), _buffer("") {
	// nothing to do...
}

/* copy constructor */
irc::Connection::Connection(const irc::Connection& conn)
: _pfd(conn._pfd), _buffer(conn._buffer) {
	// nothing to do...
}

/* destructor */
irc::Connection::~Connection(void) {
	// close fd
	close();
}


// -- private assignment operator ----------------------------------------------

/* copy assignment operator */
irc::Connection& irc::Connection::operator=(const irc::Connection& conn) {
	// copy not allowed
	return *this;
}


// -- public methods ----------------------------------------------------------

/* receive bytes */
bool irc::Connection::receive(void) {

	// check if POLLIN event occured
	if (_pfd.revents & POLLIN) {

		// declare buffer
		char buffer[BUFFER_SIZE];

		// receive bytes
		ssize_t readed = ::recv(getfd(), buffer, BUFFER_SIZE, 0);

		// check for error
		if (readed == -1) {
			std::cout << "\nError sending response to client" << std::endl;
			return false;
		}
		else if (readed == 0) {
			std::cout << "\nEmpty response from client" << std::endl;
			return false;
		}

		// append to buffer
		_buffer.append(buffer, readed);

		if (check_crlf()) { return true; }

	}
	return false;
}

/* send bytes */
ssize_t irc::Connection::send(const std::string& message) {

	ssize_t bytesSent = ::send(_pfd.fd, message.c_str(), message.size(), 0);
	if (bytesSent == -1) {
		std::cout << std::endl << "Error sending response to client" << std::endl;
	}
	return bytesSent;
}

/* close connection */
void irc::Connection::close(void) {
	// check fd validity
	if (_pfd.fd != -1) {
		// close fd
		::close(_pfd.fd);
	}
}

/* extract message */
std::string irc::Connection::extract_message(void) {

	// find CRLF
	size_t pos = _buffer.find("\r\n");

	// check if CRLF found
	if (pos != std::string::npos) {

		// extract message
		std::string message = _buffer.substr(0, pos);

		// remove message from buffer
		_buffer.erase(0, pos + 2);

		// return message
		return message;

	}

	// return empty string
	return "";
}


// -- public accessors --------------------------------------------------------

// G E T T E R S ---------

int     	irc::Connection::getfd(void) const
{
	return _pfd.fd;
}

const std::string&  irc::Connection::getnick(void) const
{
	return _nick;
}

const std::string&  irc::Connection::getuser(void) const
{
	return _user;
}

const std::string&  irc::Connection::getmsg(void) const
{
	return _msg;
}

// S E T T E R S ---------

void  irc::Connection::setnick(const std::string& str)
{
	_nick = str;
	return;
}

void  irc::Connection::setuser(const std::string& str)
{
	_user = str;
	return;
}

void  irc::Connection::setmsg(const std::string& str)
{
	_msg = str;
	return;
}

// -- private methods ---------------------------------------------------------

/* check end of message */
bool irc::Connection::check_crlf(void) {
	// find CRLF
	return _buffer.find("\r\n") != std::string::npos;
}
