#include <iostream>

#include "main.hpp"
#include "server.hpp"
#include "socket.hpp"

int main(void) {

	// server class test

	IRC::Server& server = IRC::Server::instance();

	server.start();

	server.subscribe(IRC::Client());

	server.unsubscribe(IRC::Client());

	server.broadcast("Hello World!");

	server.restart();

	server.stop();


	// socket class test

	IRC::Socket socket;

	socket.create<IRC::Inet6, IRC::Stream>();


	// end of program

	return EXIT_SUCCESS;
}
