#include "time.hpp"



/* get formatted time */
std::string irc::now(void) {
	// get current time
	std::time_t time = std::time(NULL);
	// get local time
	std::tm* ptm = std::localtime(&time);
	// check for pointer validity
	if (ptm == NULL) { return ""; }
	// declare buffer
	char buffer[32];
	// Format: Mo 15/06/2009 20:20:00
	std::strftime(buffer, 32, "%a %d/%m/%Y %H:%M:%S", ptm);
	// return formatted time
	return std::string(buffer);
}
