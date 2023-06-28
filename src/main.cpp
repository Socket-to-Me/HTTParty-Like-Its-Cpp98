#include "server.hpp"

#if defined(__linux__)
# define PORT 5000
#else
# define PORT 5052
#endif

int main(int ac, char** av) {


	irc::server& server = irc::server::instance();

	server.start("127.0.0.1", PORT);

	return EXIT_SUCCESS;
}
