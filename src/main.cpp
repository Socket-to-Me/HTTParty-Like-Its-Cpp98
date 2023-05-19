#include <iostream>

#include "sockaddr.hpp"
#include "main.hpp"
#include "server.hpp"
#include "socket.hpp"
#include "connection.hpp"

int main(int ac, char** av) {

	// // server class test

	// IRC::Server& server = IRC::Server::instance();

	// server.start();

	// server.subscribe(IRC::Client());

	// server.unsubscribe(IRC::Client());

	// server.broadcast("Hello World!");

	// server.restart();

	// server.stop();

	// IRC::Socket socket;

	// socket.create<IRC::Inet, IRC::Stream>();

	// IRC::SockAddr addr(AF_INET, 6667);



	// IRC::bind(socket, addr);


	// ------------------------------------------------

	IRC::Server& server = IRC::Server::instance();

	server.start("0.0.0.0", 5000);
	server.acceptConnections();

	//  use irssi in terminal to connect to server
	// type -> /connect 0.0.0.0 5000

	return EXIT_SUCCESS;
}
