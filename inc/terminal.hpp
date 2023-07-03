#ifndef TERMINAL_HEADER
#define TERMINAL_HEADER

// c++ headers
#include <iostream>
#include <list>
#include <csignal>

// system headers
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <fcntl.h>


// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {


	// -- T E R M  C L A S S --------------------------------------------------

	class terminal {


		public:

			// -- public types ------------------------------------------------

			/* terminal size type */
			typedef unsigned short term_size;


			// -- M E T H O D S -----------------------------------------------

			/* get singleton instance */
			static terminal& instance(void);

			/* set raw terminal */
			static void raw_terminal(void);

			/* restore original terminal */
			static void restore_terminal(void);

			/* flush stdin buffer */
			static void flush(void);

			/* get terminal size */
			static void get_terminal_size(term_size& width, term_size& height);



		private:

			// -- private constructors ----------------------------------------

			/* default constructor */
			terminal(void);

			/* destructor */
			~terminal(void);


			// -- private methods ---------------------------------------------

			/* get terminal settings */
			termios setup_terminal(void);

			/* setup raw terminal */
			void setup_raw(void);

			/* query terminal size */
			int query_terminal_size(void);



			/* signal handler */
			static void terminal_resize_handler(int signum);



			// -- M E M B E R S -----------------------------------------------

			/* singleton instance */
			static terminal _instance;

			// raw terminal flag
			bool _is_raw;

			// original terminal flag
			bool _is_origin;

			// setup flag
			bool _is_setup;

			// original terminal settings
			const termios _origin;

			// raw terminal settings
			termios _raw;

			/* terminal width */
			term_size _width;

			/* terminal height */
			term_size _height;

	};

}

#endif

