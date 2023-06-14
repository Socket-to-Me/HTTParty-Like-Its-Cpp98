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
#include "join.hpp"
#include "cmd_factory.hpp"

#include <memory>

int main(int ac, char** av) {
	

	irc::cmd_factory::cmd_maker maker = irc::cmd_factory::search("JOIN");


	if (maker) {
		irc::auto_ptr<irc::cmd> cmd = maker();

		if (cmd->evaluate() == true) {
			cmd->execute();
		}
	}*/

	return 0;

	return 0;

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


	// irc::join j;

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
	// IRC::SockAddr addr(PF_INET, 4243, "localhost");

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

	// return EXIT_SUCCESS;
}
