#include "log.hpp"


void irc::log::init(void) {
	// open alternative screen buffer
	std::cout.write("\033[?1049h", 8);
	// hide cursor
	std::cout.write("\033[?25l", 6);
	// clear screen
	std::cout.write("\033[2J", 4);
	// move cursor to top left
	std::cout.write("\033[H", 3);

}

void irc::log::exit(void) {
	// show cursor
	std::cout.write("\033[?25h", 6);
	// close alternative screen buffer
	std::cout.write("\033[?1049l", 8);
}

void irc::log::add_line(const std::string& line) {
	_logs.push_back(line);
}

void irc::log::refresh(const std::string& server_name,
		const std::size_t num_connections) {

	static std::string buffer;

	buffer.clear();


	// clear screen
	buffer.append("\033[2J", 4);
	// move cursor to top left
	buffer.append("\033[H", 3);
	// set color to green
	buffer.append("\033[32m", 5);
	// get logo
	buffer.append(irc::logo::get());
	// reset color
	buffer.append("\033[0m\n", 5);

	// print server name
	buffer.append("\x1b[33m" + server_name + "\x1b[0m\n");

	// print number of connections
	buffer.append("\x1b[33m" + std::to_string(num_connections) + " connections\x1b[0m\n");


	std::size_t i;

	// print last 3 lines
	if (_logs.size() > 20) {
		i = _logs.size() - 20;
	}
	else {
		i = 0;
	}

	for (std::size_t j = i; j < _logs.size(); j++) {
		// transform index to string
		std::string index = std::to_string(j) + " - ";
		// add index to buffer
		buffer.append(index);
		buffer.append(_logs[j]);
		buffer.push_back('\n');
	}

	// print buffer
	std::cout << buffer << std::flush;

}


// -- private static members --------------------------------------------------

/* logs */
std::vector<std::string> irc::log::_logs;
