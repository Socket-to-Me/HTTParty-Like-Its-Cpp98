#include "server.hpp"
#include "signal.hpp"



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

int check_arguments(const int ac, const char* const* av, uint16_t& port) {

	if (ac != 3) {
		std::cerr << "usage: " << av[0] << " <port> <password>" << std::endl;
		return EXIT_FAILURE;
	}

	// declare a stringstream
	std::stringstream ss(av[1]);

	// check there is only digits
	if (is_only_digits(av[1]) == false) {
		std::cerr << "\x1b[32mirc error:\x1b[0m port is not a number" << std::endl;
		return EXIT_FAILURE;
	}

	// check there is no overflow
	if (!(ss >> port)) {
		std::cerr << "\x1b[32mirc error:\x1b[0m overflow port" << std::endl;
		return EXIT_FAILURE;
	}

	// check port is in range [1024, 65535]
	if (port < 1024) {
		std::cerr << "\x1b[32mirc error:\x1b[0m reserved port" << std::endl;
		return EXIT_FAILURE;
	}

	// check password is printable
	if (is_only_printable(av[2]) == false) {
		std::cerr << "\x1b[32mirc error:\x1b[0m password is not printable" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


int main(int ac, char** av) {

	uint16_t port;

	if (check_arguments(ac, av, port) == EXIT_FAILURE)
		return EXIT_FAILURE;

	irc::server& server = irc::server::instance();
	irc::signal signal;

	server.start("127.0.0.1", port, av[2]);
	return EXIT_SUCCESS;








}
