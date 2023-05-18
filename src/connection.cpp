#include "connection.hpp"

IRC::Connection::Connection(int sd)
: _sd(sd) {

	return;
}

void IRC::Connection::send_message(const std::string& msg) {

	send(_sd, msg.c_str(), msg.length(), 0);
	return;
}

std::string IRC::Connection::receive_message(const int buffer_size) {

	std::vector<char>	buffer(buffer_size, 0);
	int 				bytesReceived;
	
	bytesReceived = recv(_sd, buffer.data(), buffer_size - 1, 0);
	if (bytesReceived == -1) {
		std::cerr << "Error in receiving message.\n";
		return "";
	}
	return std::string(buffer.data());
}

void IRC::Connection::close() {

	::close(_sd);
	return;
}

int IRC::Connection::get_sd(void) {

	return _sd;
}
