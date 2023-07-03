#include "server.hpp"
#include "signal.hpp"
#include "terminal.hpp"

#if defined(__linux__)
# define PORT 5000
#else
# define PORT 5052
#endif

#include "parser.hpp"
#include "msg.hpp"

int main(int ac, char** av) {

	/*
	std::string message = "PRIVMSG #abc hooo :Hello World!";

	irc::msg msg = irc::parser::parse(message);


	if (msg.have_command()) { std::cout << "Command: " << msg.get_command() << std::endl; }

	else { std::cout << "No command" << std::endl; }

	if (msg.have_params()) {
		std::vector<std::string> params = msg.get_params();
		for (std::vector<std::string>::iterator it = params.begin(); it != params.end(); ++it) {
			std::cout << "Param: " << *it << std::endl;
		}
	}
	else {
		std::cout << "No params" << std::endl;
	}

	if (msg.have_trailing()) {
		std::cout << "Trailing: " << msg.get_trailing() << std::endl;
	}
	else {
		std::cout << "No trailing" << std::endl;
	}


	return EXIT_SUCCESS;
	*/





	irc::server& server = irc::server::instance();

	irc::signal signal;

	server.start("127.0.0.1", PORT);

	return EXIT_SUCCESS;
}
