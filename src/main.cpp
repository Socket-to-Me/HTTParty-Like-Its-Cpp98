#include <iostream>

#include "main.hpp"
#include "server.hpp"

int main(void) {

	IRC::Server& server = IRC::Server::instance();

	server.start();

	server.subscribe(IRC::Client());

	server.unsubscribe(IRC::Client());

	server.broadcast("Hello World!");

	server.restart();

	server.stop();

	return EXIT_SUCCESS;
}
