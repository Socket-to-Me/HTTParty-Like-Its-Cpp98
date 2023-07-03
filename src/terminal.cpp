#include "terminal.hpp"


// -- private static members --------------------------------------------------

/* singleton instance */
irc::terminal irc::terminal::_instance;


// -- C O N S T R U C T O R S -------------------------------------------------

/* private default constructor */
irc::terminal::terminal(void)
:	_is_raw(false), _is_origin(false), _is_setup(false),
	_origin(setup_terminal()), _raw(),
 	_width(0), _height(0) {

	// check if original terminal settings are available
	if (_is_origin) {
		// copy original terminal settings
		_raw = _origin;
		// setup raw terminal settings
		setup_raw();
		// set setup flag
		_is_setup = true;
	}

	// query terminal size
	query_terminal_size();

	// set resize signal handler
	std::signal(SIGWINCH, &terminal::terminal_resize_handler);
}

/* destructor */
irc::terminal::~terminal(void) {
	// restore terminal settings if raw
	if (_is_raw) { restore_terminal(); }
}


// -- M E T H O D S -----------------------------------------------------------

/* get singleton instance */
irc::terminal& irc::terminal::instance(void) {
	// return singleton instance
	return _instance;
}

/* get terminal settings */
struct termios irc::terminal::setup_terminal(void) {

	// termios structure
	termios origin;

	// get current terminal settings
	if (!tcgetattr(STDIN_FILENO, &origin)) {
		// if no error, set bool flag
		_is_origin = true;
	}

	// return by value original terminal setup
	return origin;
}

/* setup raw terminal */
void irc::terminal::setup_raw(void) {


	// setup new terminal structure
	_raw.c_iflag &= ~static_cast<unsigned long>(  IXON   // disable Ctrl-S and Ctrl-Q
										| ICRNL  // disable Ctrl-M
	);

	_raw.c_lflag &= ~static_cast<unsigned long>(  ECHO   // disable echo
										| ICANON // non-canonical mode
										//| ISIG   // disable Ctrl-C and Ctrl-Z
										| IEXTEN // disable Ctrl-V and Ctrl-O
	);

	_raw.c_cc[VTIME] = 0;

	// VMIN = Minimum number of characters to read
	_raw.c_cc[VMIN] = 0;
	// VTIME = Time to wait for data (tenths of seconds)
	_raw.c_cc[VTIME] = 1;
}


/* flush stdin buffer */
void irc::terminal::flush(void) {
	// [TCIFLUSH] flushes data received but not read.
	tcflush(STDIN_FILENO, TCIFLUSH);
}

void irc::terminal::raw_terminal(void) {

	// check if terminal is setup
	if (!_instance._is_setup) { return; }

	// set non-canonical mode
	if (!tcsetattr(STDIN_FILENO, TCSANOW, &_instance._raw)) {
		_instance._is_raw = true;
	}
}

void irc::terminal::restore_terminal(void) {

	// check if terminal is setup
	if (!_instance._is_setup) { return; }

	// reset orignal terminal settings
	if (!tcsetattr(STDIN_FILENO, TCSAFLUSH, &_instance._origin)) {
		_instance._is_raw = false;
	}
}


void irc::terminal::get_terminal_size(term_size& width, term_size& height) {
	// assign reference parameters
	width  = _instance._width;
	height = _instance._height;
}

/* query terminal size */
int irc::terminal::query_terminal_size(void) {

	// winsize structure
	struct winsize win;

	// query terminal dimensions
	int err = ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);

	// check error
	if (err != -1) {
		// assign result to reference parameters
		_width = win.ws_col;
		_height = win.ws_row;
	}
	// error return
	return err;

}

void irc::terminal::terminal_resize_handler(int signum) {
	static_cast<void>(signum);
	// query terminal size
	_instance.query_terminal_size();
}



