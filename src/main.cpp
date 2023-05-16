#include <iostream>

#include "sockaddr.hpp"
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

	socket.create<IRC::Inet, IRC::Stream>();

	IRC::SockAddr addr(AF_INET, 6667);



	IRC::bind(socket, addr);


	return EXIT_SUCCESS;
}
