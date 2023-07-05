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
  _wait_pong(false),
  _last_ping(0),
  _alive(true) {
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
  _wait_pong(other._wait_pong),
  _last_ping(other._last_ping),
  _alive(other._alive) {
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
		        _pfd = other._pfd;
		     _buffer = other._buffer;
		        _msg = other._msg;
		       _nick = other._nick;
		       _user = other._user;
		   _password = other._password;
		_channelname = other._channelname;
		 _registered = other._registered;
		  _wait_pong = other._wait_pong;
		  _last_ping = other._last_ping;
		      _alive = other._alive;
	} // return self-reference
	return *this;
}


// -- public comparison operators ---------------------------------------------

/* equality operator */
bool irc::connection::operator==(const irc::connection& other) const {
    return _pfd.fd == other._pfd.fd
		&& _pfd.events == other._pfd.events
		&& _pfd.revents == other._pfd.revents
		&& _buffer == other._buffer
		&& _msg == other._msg
		&& _nick == other._nick
		&& _password == other._password
		&& _channelname == other._channelname;
}


// -- public methods ----------------------------------------------------------



/* dead routine */
bool irc::connection::dead_routine(void) {

	// check if waiting for pong
	if (_wait_pong == true) {
		// check if timeout
		if ((std::time(0) - _last_ping) > 10) {
			// set not alive
			_alive = false;
			//irc::log::add_line("Connection " + std::to_string(_pfd.fd) + " is dead. 💀");
			return true;
		}
	}

	// check if time to ping
	else if ((std::time(0) - _last_ping) > 10) {
		// send ping message
		send("PING :httparty.like.its.98\r\n");
		// update last ping time
		_last_ping = std::time(0);
		// update wait pong flag
		_wait_pong = true;
	}
	return false;
}

/* reset counter */
void irc::connection::pong(void) {
	//irc::log::add_line("Connection " + std::to_string(_pfd.fd) + " is alive. 🤖");
	_wait_pong = false;
	_last_ping = std::time(0);
}

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
		irc::log::print("Error sending response to client");
		return false;
	}
	else if (readed == 0) {
		irc::log::print("Empty response from client");
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
		irc::log::print("\x1b[31mPOLLHUP event\x1b[0m");
		return true;
	}
	// check for POLLERR event
	if (_pfd.revents & POLLERR) {
		irc::log::print("\x1b[31mPOLLERR event\x1b[0m");
		return true;
	}
	// check for POLLNVAL event
	if (_pfd.revents & POLLNVAL) {
		irc::log::print("\x1b[31mPOLLNVAL event\x1b[0m");
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

/* is alive */
bool irc::connection::is_alive(void) const {
	return _alive;
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
