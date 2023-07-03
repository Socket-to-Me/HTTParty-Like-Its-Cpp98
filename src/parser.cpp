#include "parser.hpp"



// -- P A R S E R -------------------------------------------------------------


// -- private constructors ----------------------------------------------------

/* default constructor */
irc::parser::parser(void) {
}

/* copy constructor */
irc::parser::parser(const irc::parser& parser) {
}

/* destructor */
irc::parser::~parser(void) {
}


static bool not_space(int ch) {
	return !std::isspace(ch);
}


// -- public static methods ---------------------------------------------------

irc::msg irc::parser::parse(const std::string& raw) {
	msg message;
	std::stringstream ss(raw);
	std::string item;

	// set raw
	message._raw = raw;

	// Parse tags
	if (raw[0] == '@') {
		std::getline(ss, item, ' ');
		item = item.substr(1); // Remove '@'
		std::stringstream tagss(item);
		std::string tagitem;
		while (std::getline(tagss, tagitem, ';')) {
			std::string key = tagitem.substr(0, tagitem.find('='));
			std::string value = tagitem.substr(tagitem.find('=') + 1);
			message._tags.push_back(std::make_pair(key, value));
		}
	}

	// Parse source
	if (ss.peek() == ':') {
		ss.get(); // Remove ':'
		std::getline(ss, message._source, ' ');
	}

	// Parse command
	std::getline(ss, message._command, ' ');

	// Parse parameters and trailing
	while (std::getline(ss, item, ' ')) {
		std::cout << "Item: " << item << std::endl;

		if (item[0] == ':') {
			//message._params.push_back(item.substr(1));  // Push back first word after ':'
			// Get the rest of the line, which is the trailing
			std::getline(ss, item);
			message._trailing = message._params.back() + " " + item; // Include first word after ':' and the rest
			break;
		}
		else {
			message._params.push_back(item);
		}
	}

	return message;
}

