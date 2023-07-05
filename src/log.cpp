#include "log.hpp"

#include <sstream>

template <class T>
std::string to_string(const T& value) {
	std::stringstream stream;
	stream << value;
	return stream.str();
}


// -- L O G -------------------------------------------------------------------

/* initialize log */
void irc::log::init(void) {
	// open alternative screen buffer
	std::cout.write("\033[?1049h", 8);
	// hide cursor
	std::cout.write("\033[?25l", 6);
	// clear screen
	std::cout.write("\033[2J", 4);
	// move cursor to top left
	std::cout.write("\033[H", 3);
	// set raw terminal
	irc::terminal::raw_terminal();
}

/* exit log */
void irc::log::exit(void) {
	// show cursor
	std::cout.write("\033[?25h", 6);
	// close alternative screen buffer
	std::cout.write("\033[?1049l", 8);
	// restore original terminal
	irc::terminal::restore_terminal();
}

/* add line to log */
void irc::log::add_line(const std::string& line) {
	_logs.push_back(line);

	// write to file
	std::ofstream out("log.txt", std::ios_base::app);
    out << line;
    out << "\n";
    out.close();
}

/* print */
void irc::log::print(const std::string& str) {
    irc::log::add_line(
        "["
        + irc::color::red()
        + "log"
        + irc::color::reset()
        + "] " + str);
}

/* refresh log */
void irc::log::refresh(const std::string& server_name,
					   const std::string& server_version,
					   const std::string& server_creation,
					   const std::size_t num_connections) {


	static char buff[1024];
	static std::size_t offset = 0;


	int readed = read(STDIN_FILENO, &buff, 1024);

	if (readed == 3) {
		if (buff[0] == 27) {
			if (buff[1] == '[') {
				if (buff[2] == 'A') { offset -= !!offset; }
				else if (buff[2] == 'B') {
					offset += (offset < _logs.size() - 1);
				}
			}
		}
	}


	static std::string buffer;

	buffer.clear();

	// clear screen
	buffer.append("\033[2J", 4);
	// move cursor to top left
	buffer.append("\033[H", 3);
	// set color to green
	//buffer.append("\033[32m", 5);
	// get logo
	//buffer.append(irc::logo::get());
	// reset color
	//buffer.append("\033[0m\n", 5);

	// print server name
	buffer.append(
			"\x1b[31m"
			+ std::string("server: ")
			+ "\x1b[33m"
			+ server_name +
			"\x1b[0m\n");

	// print server version
	buffer.append(
			"\x1b[31m"
			+ std::string("version: ")
			+ "\x1b[33m"
			+ server_version
			+ "\x1b[0m\n");

	// print server creation time
	buffer.append(
			"\x1b[31m"
			+ std::string("creation: ")
			+ "\x1b[33m"
			+ server_creation
			+ "\x1b[0m\n");

	// print number of connections
	buffer.append(
			"\x1b[31m"
			+ std::string("clients: ")
			+ "\x1b[33m"
			+ to_string(num_connections)
			+ " connections\x1b[0m\n\n");


	// previous line count
	std::size_t header = 5;

	// get terminal height
	unsigned short height = 0;
	unsigned short width = 0;

	irc::terminal::get_terminal_size(width, height);


	for (std::size_t j = offset;
			(j < _logs.size())
			&& (j < offset + height - header); ++j) {
		// transform index to string with leading zeros
		std::string index = to_string(j);
		while (index.size() < 4) {
			index.insert(0, "0");
		}

		// add index to buffer
		buffer.append(index);
		buffer.append(" > ");
		buffer.append(_logs[j]);
		buffer.push_back('\n');
	}

	// print buffer
	std::cout << buffer << std::flush;

}


// -- private static members --------------------------------------------------

/* logs */
std::vector<std::string> irc::log::_logs;



// -- C O L O R ---------------------------------------------------------------


// -- public static methods ---------------------------------------------------

/* red escape sequence */
std::string& irc::color::red(void) {
	static std::string red = "\033[31m";
	return red;
}

/* green escape sequence */
std::string& irc::color::green(void) {
	static std::string green = "\033[32m";
	return green;
}

/* yellow escape sequence */
std::string& irc::color::yellow(void) {
	static std::string yellow = "\033[33m";
	return yellow;
}

/* blue escape sequence */
std::string& irc::color::blue(void) {
	static std::string blue = "\033[34m";
	return blue;
}

/* magenta escape sequence */
std::string& irc::color::magenta(void) {
	static std::string magenta = "\033[35m";
	return magenta;
}

/* cyan escape sequence */
std::string& irc::color::cyan(void) {
	static std::string cyan = "\033[36m";
	return cyan;
}

/* white escape sequence */
std::string& irc::color::white(void) {
	static std::string white = "\033[37m";
	return white;
}

/* reset escape sequence */
std::string& irc::color::reset(void) {
	static std::string reset = "\033[0m";
	return reset;
}


