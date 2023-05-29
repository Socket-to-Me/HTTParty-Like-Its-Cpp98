#include <iostream>

#include "sockaddr.hpp"
#include "main.hpp"
#include "server.hpp"
#include "socket.hpp"
#include "connection.hpp"
#include "parser.hpp"


//#if define(__linux__)
#define PORT 5000
///else
//#//define port 4243
//#endif

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

	server.start("127.0.0.1", 5052);

	// ------------------------------------------------

	// std::string		str("CAP LS\nNICK swillis\nUSER swillis swillis 0.0.0.0 :Scott WILLIS");
	// IRC::Lexer		lexer(str);
	// IRC::Parser		parser(lexer);
	// std::vector< std::vector< IRC::Token > >	matrix;

	// matrix = parser.parse();

    // for (std::vector<IRC::Token>& row : matrix) {

    //     for (IRC::Token& token : row) {

    //         std::cout << token.type << "=" << token.value << std::endl;
    //     }
    // }

	// ------------------------------------------------

	// IRC::Socket socket;

	// socket.create<IRC::Inet, IRC::Stream>();

	// IRC::SockAddr addr(PF_INET, PORT, "localhost");

	// int err = IRC::bind(socket, addr);

	// if (err == -1) {
	// 	std::cout << "Failed to bind to IP/Port. " << err << std::endl;
	// 	return EXIT_FAILURE;
	// }



	//  use irssi in terminal to connect to server
	// type -> /connect 0.0.0.0 5000

	return EXIT_SUCCESS;
}
