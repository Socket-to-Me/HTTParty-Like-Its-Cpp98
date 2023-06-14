#include "connection.hpp"

IRC::Connection::Connection(const struct pollfd& pfd)
: _pfd(pfd) {

	return;
}

bool    	IRC::Connection::hasEventOccured(void)
{
	if (_pfd.revents & POLLIN)
		return true;
	return false;
}

ssize_t    	IRC::Connection::send(const std::string& message)
{
	ssize_t bytesSent = ::send(getfd(), message.c_str(), message.length(), 0);
	if (bytesSent == -1) {
		std::cout << std::endl << "Error sending response to client" << std::endl;
	}
	return bytesSent;
}

ssize_t		IRC::Connection::receive(char* buffer, int buffer_size)
{
	ssize_t	bytesReceived = ::recv(getfd(), buffer, buffer_size, 0);
	if (bytesReceived == -1) {
		std::cout << std::endl << "Error sending response to client" << std::endl;
	}
	return bytesReceived;
}

void    	IRC::Connection::close(void) 
{
	::close(getfd());
}

// G E T T E R S ---------

int     	IRC::Connection::getfd(void) const
{
	return _pfd.fd;
}

const std::string&  IRC::Connection::getnick(void) const
{
	return _nick;
}

const std::string&  IRC::Connection::getuser(void) const
{
	return _user;
}

// S E T T E R S ---------

void  IRC::Connection::setnick(const std::string& str)
{
	_nick = str;
	return;
}

void  IRC::Connection::setuser(const std::string& str)
{
	_user = str;
	return;
}
