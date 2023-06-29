#ifndef LOG_HEADER
# define LOG_HEADER

// c++ standard headers
#include <vector>
#include <string>
#include <iostream>


#include "logo.hpp"


// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {

	// -- L O G  C L A S S ------------------------------------------------------

	class log {

		public:

			static void init(void);
			static void exit(void);

			static void add_line(const std::string&);

			static void refresh(const std::string&,
					const std::size_t);

			static std::vector<std::string> _logs;


	};

}




#endif
