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
  _channelname(""),
  _registered(false),
  _alive(pfd.fd) {
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
  _channelname(other._channelname),
  _registered(other._registered),
  _alive(other._alive) {
	return;
}

/* destructor */
irc::connection::~connection(void) {
	// close fd
	close();
}


// -- public assignment operators ---------------------------------------------

/* copy assignment operator */
irc::connection& irc::connection::operator=(const irc::connection& other) {
	// check for self-assignment
	if (this != &other) {
		// assign members
		        _pfd = other.getpfd();
		     _buffer = other.getbuffer();
		        _msg = other.getmsg();
		       _nick = other.getnick();
		       _user = other.getuser();
		   _password = other.getpassword();
		_channelname = other.getchannelname();
		 _registered = other.is_registered();
		     _alive = other._alive;
	} // return self-reference
	return *this;
}


// -- public comparison operators ---------------------------------------------

/* equality operator */
bool irc::connection::operator==(const irc::connection& other) const {
    return _pfd.fd == other.getfd()
		&& _pfd.events == other.getevents()
		&& _pfd.revents == other.getrevents()
		&& _buffer == other.getbuffer()
		&& _msg == other.getmsg()
		&& _nick == other.getnick()
		&& _password == other.getpassword()
		&& _channelname == other.getchannelname();
}


// -- public methods ----------------------------------------------------------

/* receive bytes */
bool irc::connection::receive(void) {
	// check for complete message in buffer
	if (check_crlf()) { return true; }
	// check for POLLIN event
	if (_pfd.revents & POLLIN) { return read(); }
	// else return false
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
		irc::log::add_line("Error sending response to client");
		return false;
	}
	else if (readed == 0) {
		irc::log::add_line("Empty response from client");
		return false;
	}

	// append to buffer
	_buffer.append(buffer, readed);

	// check for complete message in buffer
	return check_crlf();
}

/* check fails */
bool irc::connection::check_fails(void) {
	// check for POLLHUP event
	if (_pfd.revents & POLLHUP) {
		irc::log::add_line("Client disconnected");
		return true;
	}
	// check for POLLERR event
	if (_pfd.revents & POLLERR) {
		irc::log::add_line("Error in client connection");
		return true;
	}
	// check for POLLNVAL event
	if (_pfd.revents & POLLNVAL) {
		irc::log::add_line("Invalid request from client");
		return true;
	}
	// else return false
	return false;
}

/* send bytes */
ssize_t irc::connection::send(const std::string& message) const {


	irc::log::add_line(
			irc::color::blue()
			+ "Sending response to client: "
			+ irc::color::reset()
			+ "[" + getnick() + "] " + message.substr(0, message.size() - 2));


	ssize_t bytesSent = ::send(_pfd.fd, message.c_str(), message.size(), 0);
	if (bytesSent == -1) {
		irc::log::add_line("Error sending response to client: " + std::string(strerror(errno)));
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

/* init alive */
void irc::connection::init_alive(const std::string& server_name) {
	_alive.set_server_name(server_name);
}

/* pong */
void irc::connection::pong(void) {
	_alive.pong();
}


// -- public accessors --------------------------------------------------------

/* get pollfd reference */
const struct pollfd& irc::connection::getpfd(void) const {
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

const std::string&   irc::connection::gettarget(void) const
{
	return _target;
}

/* is registered */
bool irc::connection::is_registered(void) const {
	return _registered;
}

/* is alive */
bool irc::connection::is_alive(void) {
	return _alive.is_alive();
}


// S E T T E R S ---------

/* register client */
void irc::connection::register_client(void) {
	_registered = true;
}

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

void  irc::connection::settarget(const std::string& str)
{
	_target = str;
	return;
}

// -- private methods ---------------------------------------------------------

/* check end of message */
bool irc::connection::check_crlf(void) {
	// find CRLF
	return _buffer.find("\r\n") != std::string::npos;
}
