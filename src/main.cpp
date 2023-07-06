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


bool is_only_digits(const char* arg) {
	while (*arg) { if (!std::isdigit(*arg))
			return false;
		++arg;
	} return true;
}

bool is_only_printable(const char* arg) {
	while (*arg) { if (!std::isprint(*arg))
			return false;
		++arg;
	} return true;
}

int check_arguments(const int ac, const char* const* av, std::uint16_t& port) {

	if (ac != 3) {
		std::cerr << "usage: " << av[0] << " <port> <password>" << std::endl;
		return EXIT_FAILURE;
	}

	// TODO: check if port is a number
	std::stringstream ss(av[1]);

	if (is_only_digits(av[1]) == false) {
		std::cerr << "\x1b[32mirc error:\x1b[0m port is not a number" << std::endl;
		return EXIT_FAILURE;
	}

	if (!(ss >> port)) {
		std::cerr << "\x1b[32mirc error:\x1b[0m overflow port" << std::endl;
		return EXIT_FAILURE;
	}

	if (is_only_printable(av[2]) == false) {
		std::cerr << "\x1b[32mirc error:\x1b[0m password is not printable" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


int main(int ac, char** av) {

	std::uint16_t port;

	if (check_arguments(ac, av, port) == EXIT_FAILURE)
		return EXIT_FAILURE;

	irc::server& server = irc::server::instance();
	irc::signal signal;

	server.start("127.0.0.1", port);
	return EXIT_SUCCESS;








}
