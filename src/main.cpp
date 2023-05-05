#include <iostream>

#include "main.hpp"
#include "server.hpp"
#include "socket.hpp"

int main(void) {

	IRC::Server& server = IRC::Server::instance();

	server.start();

	server.subscribe(IRC::Client());

	server.unsubscribe(IRC::Client());

	server.broadcast("Hello World!");

	server.restart();

	server.stop();

	IRC::Socket socket;

	socket.create(AF_INET, SOCK_STREAM, 0);

	return EXIT_SUCCESS;
}
