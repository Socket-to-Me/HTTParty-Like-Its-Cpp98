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
  _host(""),
  _realname(""),
  _channelname(""),
  _registered(false),
  _duplicated(false),
  _wait_pong(false),
  _last_ping(0),
  _alive(true),
  _have_user(false),
  _have_nick(false),
  _have_pass(false) {
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
  _host(other._host),
  _realname(other._realname),
  _channelname(other._channelname),
  _registered(other._registered),
  _duplicated(other._duplicated),
  _wait_pong(other._wait_pong),
  _last_ping(other._last_ping),
  _alive(other._alive),
  _have_user(other._have_user),
  _have_nick(other._have_nick),
  _have_pass(other._have_pass) {
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
			   _host = other._host;
		   _realname = other._realname;
		_channelname = other._channelname;
		 _registered = other._registered;
		 _duplicated = other._duplicated;
		  _wait_pong = other._wait_pong;
		  _last_ping = other._last_ping;
		      _alive = other._alive;
		  _have_user = other._have_user;
		  _have_nick = other._have_nick;
		  _have_pass = other._have_pass;
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
		&& _user == other._user
		&& _password == other._password
		&& _host == other._host
		&& _realname == other._realname
		&& _channelname == other._channelname
		&& _registered == other._registered
		&& _duplicated == other._duplicated
		&& _wait_pong == other._wait_pong
		&& _last_ping == other._last_ping
		&& _alive == other._alive
		&& _have_user == other._have_user
		&& _have_nick == other._have_nick
		&& _have_pass == other._have_pass;
}


// -- public methods ----------------------------------------------------------

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
	if (_pfd.revents & POLLIN) { return read(); }	//TODO <<< nc infinite loop here most likely
	// else return false
	return false;
}



/* read bytes after new connection */
bool irc::connection::read(void) {

	// declare buffer
	char buffer[BUFFER_SIZE];

	// receive bytes
	ssize_t readed = ::recv(_pfd.fd, buffer, BUFFER_SIZE, 0);

	// {
	// 	std::stringstream ss;
	// 	ss << _pfd.fd;
	// 	std::string str = ss.str();
	// 	irc::log::print(str);
	// }
	// {
	// 	irc::log::print(std::string(buffer, readed));
	// }

	// check for error
	if (readed == -1) {
		irc::log::print("Error receiving response from client");
		return false;
	}
	else if (readed == 0) {
		// irc::log::print("Empty response from client");
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

const std::string&  irc::connection::gethost(void) const
{
	return _host;
}

const std::string&  irc::connection::getrealname(void) const
{
	return _realname;
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

/* is duplicated */
bool irc::connection::is_duplicated(void) const {
	return _duplicated;
}

/* have pass */
bool irc::connection::have_pass(void) const {
	return _have_pass;
}

/* have nick */
bool irc::connection::have_nick(void) const {
	return _have_nick;
}

/* have user */
bool irc::connection::have_user(void) const {
	return _have_user;
}


// S E T T E R S ---------

/* register client */
void irc::connection::register_client(void) {
	_registered = true;
}

/* duplicate nick */
void irc::connection::duplicate_nick(void) {
	_duplicated = true;
}

/* duplicate nick */
void irc::connection::not_duplicate_nick(void) {
	_duplicated = false;
}

void  irc::connection::setnick(const std::string& str) {
	_nick = str;
	return;
}

void  irc::connection::setuser(const std::string& str) {
	_user = str;
	return;
}

void  irc::connection::sethost(const std::string& str) {
	_host = str;
	return;
}

void  irc::connection::setrealname(const std::string& str) {
	_realname = str;
	return;
}

void  irc::connection::setmsg(const std::string& str) {
	_msg = str;
	return;
}

void  irc::connection::setpassword(const std::string& str) {
	_password = str;
	return;
}

void  irc::connection::setchannelname(const std::string& str) {
	_channelname = str;
	return;
}

void  irc::connection::settarget(const std::string& str) {
	_target = str;
	return;
}

/* validate pass */
void irc::connection::validate_pass(void) {
	_have_pass = true;
}

/* validate nick */
void irc::connection::validate_nick(void) {
	_have_nick = true;
}

/* validate user */
void irc::connection::validate_user(void) {
	_have_user = true;
}


// -- private methods ---------------------------------------------------------

/* check end of message */
bool irc::connection::check_crlf(void) {
	// find CRLF
	return _buffer.find("\r\n") != std::string::npos;
}
