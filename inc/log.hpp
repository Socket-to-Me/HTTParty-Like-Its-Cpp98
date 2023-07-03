#ifndef LOG_HEADER
# define LOG_HEADER

// c++ standard headers
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "terminal.hpp"
#include "logo.hpp"


// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {


	// -- L O G ---------------------------------------------------------------

	class log {


		public:

			// -- public static methods ---------------------------------------

			/* initialize log */
			static void init(void);

			/* exit log */
			static void exit(void);

			/* add line to log */
			static void add_line(const std::string&);

			/* print */
			static void	print(const std::string& str);

			/* refresh log */
			static void refresh(
					const std::string&, // server name
					const std::string&, // server version
					const std::string&, // server creation time
					const std::size_t   // number of clients
					);


		private:

			// -- private static members --------------------------------------

			/* log lines */
			static std::vector<std::string> _logs;

	};


	// -- C O L O R -----------------------------------------------------------

	class color {

		public:


			// -- public static methods ---------------------------------------

			/* red escape sequence */
			static std::string& red(void);

			/* green escape sequence */
			static std::string& green(void);

			/* yellow escape sequence */
			static std::string& yellow(void);

			/* blue escape sequence */
			static std::string& blue(void);

			/* magenta escape sequence */
			static std::string& magenta(void);

			/* cyan escape sequence */
			static std::string& cyan(void);

			/* white escape sequence */
			static std::string& white(void);

			/* reset escape sequence */
			static std::string& reset(void);

	};

}




#endif
