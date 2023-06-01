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

int     	IRC::Connection::getfd(void)
{
	return _pfd.fd;
}
