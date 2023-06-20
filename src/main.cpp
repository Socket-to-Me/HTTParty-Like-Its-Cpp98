#include <iostream>

#include "sockaddr.hpp"
#include "main.hpp"
#include "server.hpp"
#include "socket.hpp"
#include "connection.hpp"
#include "parser.hpp"


#if define(__linux__)
# define PORT 5000
#else
# define PORT 4243
#endif

#include "join.hpp"
#include "cmd_factory.hpp"

#include <memory>

int main(int ac, char** av) {
	

	irc::cmd_factory::cmd_maker maker = irc::cmd_factory::search("CAP");

	if (maker) {

		std::vector<irc::token> tk;

		tk.push_back(irc::token("CAP", COMMAND_TOKEN));
		tk.push_back(irc::token("LS", COMMAND_TOKEN));

		irc::auto_ptr<irc::cmd> cmd1 = maker();
		irc::auto_ptr<irc::cmd> cmd2 = maker(tk);

		if (cmd1->evaluate() == true) {
			cmd1->execute();
		}

		if (cmd2->evaluate() == true) {
			cmd2->execute();
		}
	}

	return 0;

	// // server class test

	// irc::Server& server = irc::Server::instance();

	// server.start();

	// server.subscribe(irc::Client());

	// server.unsubscribe(irc::Client());

	// server.broadcast("Hello World!");

	// server.restart();

	// server.stop();

	// irc::Socket socket;

	// socket.create<irc::Inet, irc::Stream>();

	// irc::SockAddr addr(AF_INET, 6667);


	// irc::join j;

	// irc::bind(socket, addr);


	// ------------------------------------------------

	irc::Server& server = irc::Server::instance();

	server.start("127.0.0.1", 5052);

	// ------------------------------------------------

	// std::string		str("CAP LS\nNICK swillis\nUSER swillis swillis 0.0.0.0 :Scott WILLIS");
	// irc::Lexer		lexer(str);
	// irc::Parser		parser(lexer);
	// std::vector< std::vector< irc::Token > >	matrix;

	// matrix = parser.parse();
	// irc::SockAddr addr(PF_INET, 4243, "localhost");

    // for (std::vector<irc::Token>& row : matrix) {

    //     for (irc::Token& token : row) {

    //         std::cout << token.type << "=" << token.value << std::endl;
    //     }
    // }

	// ------------------------------------------------

	// irc::Socket socket;

	// socket.create<irc::Inet, irc::Stream>();

	// irc::SockAddr addr(PF_INET, PORT, "localhost");

	// int err = irc::bind(socket, addr);

	// if (err == -1) {
	// 	std::cout << "Failed to bind to IP/Port. " << err << std::endl;
	// 	return EXIT_FAILURE;
	// }



	//  use irssi in terminal to connect to server
	// type -> /connect 0.0.0.0 5000

	// return EXIT_SUCCESS;
}
