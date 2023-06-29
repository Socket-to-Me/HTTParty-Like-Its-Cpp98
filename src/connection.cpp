#include "connection.hpp"

// -- C O N N E C T I O N -----------------------------------------------------


// -- public constructors -----------------------------------------------------

/* pollfd reference constructor */
irc::connection::connection(struct pollfd& pfd)
: _pfd(pfd), 
  _buffer(""),
  _msg(""),
  _nick(""),
  _user(""),
  _password(""),
  _channelname("") {
	return;
}

/* copy constructor */
irc::connection::connection(const irc::connection& other)
: _pfd(other._pfd), 
  _buffer(other._buffer),
  _msg(other._msg),
  _nick(other._nick),
  _user(other._user),
  _password(other._password),
  _channelname(other._channelname) {
	return;
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
		_password = other.getpassword();
		_channelname = other.getchannelname();

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
		&& _password == other.getpassword()
		&& _channelname = other.getchannelname();
}

// -- public methods ----------------------------------------------------------

/* receive bytes */
bool irc::connection::receive(void) {

	if (check_crlf()) { return true; }

	// check if POLLIN event occured
	if (_pfd.revents & POLLIN) {
		return read();
	}
	return false;
}

/* read bytes after new connection */
bool irc::connection::read(void) {

	// declare buffer
	char buffer[BUFFER_SIZE];

	// receive bytes
	ssize_t readed = ::recv(_pfd.fd, buffer, BUFFER_SIZE, 0);

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

	return false;
}

/* send bytes */
ssize_t irc::connection::send(const std::string& message) {

	// std::cout << std::endl << "----- S E N D I N G (" + getnick() + ") -----" << std::endl << std::endl;
	// std::cout << message.c_str() << std::endl;

	ssize_t bytesSent = ::send(getfd(), message.c_str(), message.size(), 0);
	if (bytesSent == -1) {
		std::cout << std::endl << "Error sending response to client: " << strerror(errno) << std::endl;
	}
	return bytesSent;
}

/* close connection */
void irc::connection::close(void) {
	// // check fd validity
	// if (_pfd.fd != -1) {
	// 	// close fd
	// 	::close(_pfd.fd);
	// }
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

const std::string&   irc::connection::getchannelname(void) const
{
	return _channelname;
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

void  irc::connection::setchannelname(const std::string& str)
{
	_channelname = str;
	return;
}

// -- private methods ---------------------------------------------------------

/* check end of message */
bool irc::connection::check_crlf(void) {
	// find CRLF
	return _buffer.find("\r\n") != std::string::npos;
}
