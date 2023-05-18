#include "Connection.hpp"

Connection::Connection(int sd)
: _sd(sd) {

	return;
}

void Connection::send_message(const std::string& msg) {

	send(_sd, msg.c_str(), msg.length(), 0);
}

std::string Connection::receive_message(const int buffer_size) {

	char	buffer[buffer_size];
	int 	bytesReceived;

	memset(buffer, 0, buffer_size);
	bytesReceived = recv(_sd, buffer, buffer_size - 1, 0);
	if (bytesReceived == -1) {
		std::cerr << "Error in receiving message.\n";
		return "";
	}
	return std::string(buffer);
}

void Connection::close() {

	::close(_sd);
}
