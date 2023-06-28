#include "connection.hpp"


// -- C O N N E C T I O N -----------------------------------------------------


// -- public constructors -----------------------------------------------------

/* pollfd reference constructor */
irc::connection::connection(struct pollfd& pfd)
: _pfd(pfd), _buffer("") {
	// nothing to do...
}

/* copy constructor */
irc::connection::connection(const irc::connection& conn)
: _pfd(conn._pfd), _buffer(conn._buffer) {
	// nothing to do...
}

/* destructor */
irc::connection::~connection(void) {
	// close fd
	close();
}


/* copy assignment operator */
irc::connection& irc::connection::operator=(const irc::connection& other) {

	if (this != &other) // not a self-assignment
	{
		_pfd = other.getpfd();
		_buffer = other.getbuffer();
		_msg = other.getmsg();
		_nick = other.getnick();
		_user = other.getuser();

	}
	return *this;
}

/* == operator */
bool irc::connection::operator==(const irc::connection& other) const
{
    return _pfd.fd == other.getfd() 
		&& _pfd.events == other.getevents()
		&& _pfd.revents == other.getrevents()
		&& _buffer == other.getbuffer()
		&& _msg == other.getmsg()
		&& _nick == other.getnick()
		&& _user == other.getuser();
}

// -- public methods ----------------------------------------------------------

/* receive bytes */
bool irc::connection::receive(void) {

	// check if POLLIN event occured
	if (_pfd.revents & POLLIN) {

		std::cout << "read into buffer" << std::endl;

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
ssize_t irc::connection::send(const std::string& message) {

	ssize_t bytesSent = ::send(_pfd.fd, message.c_str(), message.size(), 0);
	if (bytesSent == -1) {
		std::cout << std::endl << "Error sending response to client" << std::endl;
	}
	return bytesSent;
}

/* close connection */
void irc::connection::close(void) {
	// check fd validity
	if (_pfd.fd != -1) {
		// close fd
		::close(_pfd.fd);
	}
}

/* extract message */
std::string irc::connection::extract_message(void) {

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

const struct pollfd& irc::connection::getpfd(void) const
{
	return _pfd;
}


int	irc::connection::getfd(void) const
{
	return _pfd.fd;
}

short	irc::connection::getevents(void) const
{
	return _pfd.events;
}

short	irc::connection::getrevents(void) const
{
	return _pfd.revents;
}

const std::string&  irc::connection::getnick(void) const
{
	return _nick;
}

const std::string&  irc::connection::getuser(void) const
{
	return _user;
}

const std::string&  irc::connection::getmsg(void) const
{
	return _msg;
}

const std::string&  irc::connection::getbuffer(void) const
{
	return _buffer;
}

const std::string&  irc::connection::getpassword(void) const
{
	return _password;
}

// S E T T E R S ---------

void  irc::connection::setnick(const std::string& str)
{
	_nick = str;
	return;
}

void  irc::connection::setuser(const std::string& str)
{
	_user = str;
	return;
}

void  irc::connection::setmsg(const std::string& str)
{
	_msg = str;
	return;
}

void  irc::connection::setpassword(const std::string& str)
{
	_password = str;
	return;
}

// -- private methods ---------------------------------------------------------

/* check end of message */
bool irc::connection::check_crlf(void) {
	// find CRLF
	return _buffer.find("\r\n") != std::string::npos;
}
