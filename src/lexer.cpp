#include "lexer.hpp"



// -- N E W  L E X E R --------------------------------------------------------


/* look up table */
const irc::lexer::table irc::lexer::_lookup = {

		// -- D E F A U L T  S T A T E ----------------------------------------
		{
			transition(DEFAULT_STATE,  token::UNDEFINED_TOKEN, COUNT), // NULL
			transition(DEFAULT_STATE,  token::UNDEFINED_TOKEN, COUNT), // CTRL

			transition(COMMAND_STATE,  token::UNDEFINED_TOKEN, COUNT), // OTHER
			transition(SOURCE_STATE,   token::UNDEFINED_TOKEN, COUNT), // COLON
			transition(TAG_STATE,      token::UNDEFINED_TOKEN, COUNT), // AT

			transition(DEFAULT_STATE,  token::UNDEFINED_TOKEN, SKIP), // SPACE
			transition(DEFAULT_STATE,  token::UNDEFINED_TOKEN, SKIP), // NEWLINE
			transition(DEFAULT_STATE,  token::UNDEFINED_TOKEN, SKIP), // CARRIAGE_RETURN

		},

		// -- T A G  S T A T E ------------------------------------------------
		{
			transition(DEFAULT_STATE,  token::UNDEFINED_TOKEN, COUNT), // NULL
			transition(DEFAULT_STATE,  token::UNDEFINED_TOKEN, COUNT), // CTRL

			transition(TAG_STATE,      token::UNDEFINED_TOKEN, COUNT), // OTHER
			transition(TAG_STATE,      token::UNDEFINED_TOKEN, COUNT), // COLON
			transition(TAG_STATE,      token::UNDEFINED_TOKEN, COUNT), // AT

			transition(DEFAULT_STATE,  token::TAG_TOKEN,       APPEND), // SPACE
			transition(TAG_STATE,      token::TAG_TOKEN,       APPEND), // NEWLINE
			transition(DEFAULT_STATE,  token::TAG_TOKEN,       APPEND), // CARRIAGE_RETURN

		},

		// -- T A G  S T A T E ------------------------------------------------
		{
			transition(DEFAULT_STATE,  token::UNDEFINED_TOKEN, COUNT), // NULL
			transition(DEFAULT_STATE,  token::UNDEFINED_TOKEN, COUNT), // CTRL

			transition(TAG_STATE,      token::UNDEFINED_TOKEN, COUNT), // OTHER
			transition(TAG_STATE,      token::UNDEFINED_TOKEN, COUNT), // COLON
			transition(TAG_STATE,      token::UNDEFINED_TOKEN, COUNT), // AT

			transition(DEFAULT_STATE,  token::TAG_TOKEN,       APPEND), // SPACE
			transition(DEFAULT_STATE,  token::TAG_TOKEN,       APPEND), // NEWLINE
			transition(DEFAULT_STATE,  token::TAG_TOKEN,       APPEND), // CARRIAGE_RETURN

		},

		// -- S O U R C E  S T A T E ------------------------------------------
		{
			transition(DEFAULT_STATE,  token::UNDEFINED_TOKEN, COUNT), // NULL
			transition(DEFAULT_STATE,  token::UNDEFINED_TOKEN, COUNT), // CTRL

			transition(SOURCE_STATE,   token::UNDEFINED_TOKEN, COUNT), // OTHER
			transition(SOURCE_STATE,   token::UNDEFINED_TOKEN, COUNT), // COLON
			transition(SOURCE_STATE,   token::UNDEFINED_TOKEN, COUNT), // AT

			transition(DEFAULT_STATE,  token::SOURCE_TOKEN,    APPEND), // SPACE
			transition(DEFAULT_STATE,  token::SOURCE_TOKEN,    APPEND), // NEWLINE
			transition(DEFAULT_STATE,  token::SOURCE_TOKEN,    APPEND), // CARRIAGE_RETURN

		},

		// -- C O M M A N D  S T A T E ----------------------------------------
		{
			transition(DEFAULT_STATE,  token::UNDEFINED_TOKEN, COUNT), // NULL
			transition(DEFAULT_STATE,  token::UNDEFINED_TOKEN, COUNT), // CTRL

			transition(COMMAND_STATE,  token::UNDEFINED_TOKEN, COUNT), // OTHER
			transition(COMMAND_STATE,  token::UNDEFINED_TOKEN, COUNT), // COLON
			transition(COMMAND_STATE,  token::UNDEFINED_TOKEN, COUNT), // AT

			transition(DEFAULT_STATE,  token::COMMAND_TOKEN,   APPEND), // SPACE
			transition(DEFAULT_STATE,  token::COMMAND_TOKEN,   APPEND), // NEWLINE
			transition(DEFAULT_STATE,  token::COMMAND_TOKEN,   APPEND), // CARRIAGE_RETURN

		},


};

/* action table */
const irc::lexer::action irc::lexer::_actions = {
	&irc::lexer::skip,           // SKIP
	&irc::lexer::count,          // COUNT
	&irc::lexer::append,         // APPEND
	&irc::lexer::end_of_message, // END_OF_MESSAGE
};

/* char table (256) */
const irc::lexer::char_table irc::lexer::_chars = {
	// 0x00 null
	NULL_CHAR,
	// 0x01 - 0x09 ctrl
	CTRL_CHAR, CTRL_CHAR, CTRL_CHAR, CTRL_CHAR,
	CTRL_CHAR, CTRL_CHAR, CTRL_CHAR, CTRL_CHAR,
	CTRL_CHAR,
	// 0x0A newline
	NL_CHAR,
	// 0x0B - 0x0C ctrl
	CTRL_CHAR, CTRL_CHAR,
	// 0x0D carriage return
	CR_CHAR, // 13
	// 0x0E - 0x1F ctrl
	CTRL_CHAR, CTRL_CHAR, CTRL_CHAR, CTRL_CHAR,
	CTRL_CHAR, CTRL_CHAR, CTRL_CHAR, CTRL_CHAR,
	CTRL_CHAR, CTRL_CHAR, CTRL_CHAR, CTRL_CHAR,
	CTRL_CHAR, CTRL_CHAR, CTRL_CHAR, CTRL_CHAR,
	CTRL_CHAR, CTRL_CHAR,
	// 0x20 space
	SPACE_CHAR,
	// 0x21 - 0x39 other
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	// 0x3A colon
	COLON_CHAR,
	// 0x3B - 0x3F other
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR,
	// 0x40 at
	AT_CHAR,
	// 0x41 - 0xFF other
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR, OTHER_CHAR, OTHER_CHAR, OTHER_CHAR,
	OTHER_CHAR
};


/* state debug */
const irc::lexer::state_debug irc::lexer::_state_debug = {
	"DEFAULT_STATE",

	"TAG_STATE",
	"TAG_END_STATE",

	"SOURCE_STATE",
	"SOURCE_END_STATE",

	"COMMAND_STATE",
	"COMMAND_END_STATE",
};

/* action debug */
const irc::lexer::action_debug irc::lexer::_action_debug = {
	"SKIP",
	"COUNT",
	"APPEND",
	"END_OF_MESSAGE"
};

/* char debug */
const irc::lexer::char_debug irc::lexer::_char_debug = {
	"NULL",
	"CTRL",
	"OTHER",
	"COLON",
	"AT",
	"SPACE",
	"NEWLINE",
	"CARRIAGE_RETURN",
};


// -- T R A N S I T I O N -----------------------------------------------------


// -- public constructors -----------------------------------------------------

// temporary DEFAULT constructor
// to be REMOVED !!!
irc::lexer::transition::transition(void) {
	// nothing to do...
}

/* default constructor */
irc::lexer::transition::transition(const irc::lexer_state state, const irc::token_type type, const irc::lexer_action action)
: _state(state), _type(type), _action(action) {
	// nothing to do...
}

/* copy constructor */
irc::lexer::transition::transition(const irc::lexer::transition& other)
: _state(other._state), _type(other._type), _action(other._action) {
	// nothing to do...
}

/* destructor */
irc::lexer::transition::~transition(void) {
	// nothing to do...
}


// -- public assignment operator ----------------------------------------------

/* copy assignment operator */
irc::lexer::transition& irc::lexer::transition::operator=(const irc::lexer::transition& other) {
	// copy data members
	_state  = other._state;
	_type   = other._type;
	_action = other._action;
	// return self reference
	return *this;
}

// -- public accessors --------------------------------------------------------

/* get lexer state */
irc::lexer_state irc::lexer::transition::state(void) const {
	// return state
	return _state;
}

/* get token type */
irc::token_type irc::lexer::transition::type(void) const {
	// return type
	return _type;
}

/* get lexer action */
irc::lexer_action irc::lexer::transition::action(void) const {
	// return action
	return _action;
}




// -- L E X E R ---------------------------------------------------------------


// -- private constructors ----------------------------------------------------

/* default constructor */
irc::lexer::lexer(message_list& msgs, const std::string& str)
: _msgs(msgs), _str(str),
  _idx(0), _count(0),
  _transition(DEFAULT_STATE, token::UNDEFINED_TOKEN, SKIP) {
	// nothing to do...
}

/* copy constructor */
irc::lexer::lexer(const irc::lexer& other)
: _msgs(other._msgs), _str(other._str),
  _idx(other._idx), _count(other._count),
  _transition(other._transition) {
	// nothing to do...
}

/* destructor */
irc::lexer::~lexer(void) {
	// nothing to do...
}


// -- public static methods ---------------------------------------------------

/* static lex */
void irc::lexer::lex(message_list& msgs, const std::string& to_lex) {
	// instantiate lexer and call lex method
	lexer(msgs, to_lex).lex();
}



// -- private methods ---------------------------------------------------------

/* lex */
void irc::lexer::lex(void) {

	// clear previous message list
	_msgs.clear();

	// check if string is empty
	if (_str.empty()) { return; }

	do {

		// get current character (need implementation)
		char_type ct = _chars[(unsigned char)_str[_idx]];

		// debug
		std::cout << "current character: " << _str[_idx] << " (" << _char_debug[ct] << ")\n"
				  << "    current state: " << _state_debug[_transition.state()] << "\n";


		// get transition
		_transition = _lookup[_transition.state()][ct];

		// debug
		std::cout << "       next state: " << _state_debug[_transition.state()] << "\n"
				  << "      next action: " << _action_debug[_transition.action()] << "\n\n";


		// execute action
		(this->*_actions[_transition.action()])();


	} while (_idx++ < _str.size());


}

/* skip */
void irc::lexer::skip(void) {
	// do nothing...
}

/* count */
void irc::lexer::count(void) {
	// increment count
	++_count;
}

/* append */
void irc::lexer::append(void) {
	// get pointer to token start
	const char* ptr = _str.c_str() + _idx - _count;
	// append new token to message list
	_msgs.append(ptr, _count, _transition.type());
	_count = 0;
}

/* end of message */
void irc::lexer::end_of_message(void) {
	append();
	_msgs.new_message();
}



// -- T O K E N ---------------------------------------------------------------


// -- public constructors -----------------------------------------------------

/* c-string and type constructor */
irc::token::token(const char* value, const irc::token::size_type size, const irc::token_type type)
: _value(value, size), _type(type) {
	// nothing to do...
}

/* string and type constructor */
irc::token::token(const std::string& value, const irc::token_type type)
: _value(value), _type(type) {
	// nothing to do...
}

/* copy constructor */
irc::token::token(const irc::token& other)
: _value(other._value), _type(other._type) {
	// nothing to do...
}

/* destructor */
irc::token::~token(void) {
	// nothing to do...
}


// -- public assignment operator ----------------------------------------------

/* copy assignment operator */
irc::token& irc::token::operator=(const irc::token& other) {
	// copy data members
	_value = other._value;
	_type  = other._type;
	// return self reference
	return *this;
}


// -- public accessors --------------------------------------------------------

/* get value */
const std::string& irc::token::value(void) const {
	// return value
	return _value;
}

/* get type */
irc::token_type irc::token::type(void) const {
	// return type
	return _type;
}


// -- public setters ----------------------------------------------------------

/* set value */
void irc::token::value(const std::string& value) {
	// set value
	_value.assign(value);
}

/* set value with c-string */
void irc::token::value(const char* value, const irc::token::size_type size) {
	// set value
	_value.assign(value, size);
}

/* set type */
void irc::token::type(const irc::token_type type) {
	// set type
	_type = type;
}




// -- M E S S A G E -----------------------------------------------------------

// -- public constructors -----------------------------------------------------

/* default constructor */
irc::message::message(void)
: _tokens() {
	// nothing to do...
}

/* copy constructor */
irc::message::message(const irc::message& other)
: _tokens(other._tokens) {
	// nothing to do...
}

/* destructor */
irc::message::~message(void) {
	// nothing to do...
}


// -- public assignment operator ----------------------------------------------

/* copy assignment operator */
irc::message& irc::message::operator=(const irc::message& other) {
	// check for self assignment
	if (this != &other) {
		// copy data members
		_tokens = other._tokens;
	} // return self reference
	return *this;
}


// -- public subscript operator -----------------------------------------------

/* subscript operator */
const irc::token& irc::message::operator[](const size_type idx) const {
	// return token
	return _tokens[idx];
}


// -- public accessors --------------------------------------------------------

/* get size */
irc::message::size_type irc::message::size(void) const {
	// return size
	return _tokens.size();
}


// -- public modifiers --------------------------------------------------------

/* append token */
void irc::message::append(const irc::token& token) {
	// append token
	_tokens.push_back(token);
}

/* append token with c-string value and type */
void irc::message::append(const char* value, const irc::token::size_type size, const irc::token_type type) {
	// append token
	_tokens.push_back(token(value, size, type));
}

/* append token with string value and type */
void irc::message::append(const std::string& value, const irc::token_type type) {
	// append token
	_tokens.push_back(token(value, type));
}



// -- M E S S A G E  L I S T --------------------------------------------------

// -- public constructors -----------------------------------------------------

/* default constructor */
irc::message_list::message_list(void)
: _msgs(), _idx(0) {
	// nothing to do...
}

/* copy constructor */
irc::message_list::message_list(const irc::message_list& other)
: _msgs(other._msgs), _idx(other._idx) {
	// nothing to do...
}

/* destructor */
irc::message_list::~message_list(void) {
	// nothing to do...
}


// -- public assignment operator ----------------------------------------------

/* copy assignment operator */
irc::message_list& irc::message_list::operator=(const irc::message_list& other) {
	// check for self assignment
	if (this != &other) {
		// copy data members
		_msgs = other._msgs;
		_idx  = other._idx;
	} // return self reference
	return *this;
}


// -- public subscript operator -----------------------------------------------

/* subscript operator */
const irc::message& irc::message_list::operator[](const size_type idx) const {
	// return message
	return _msgs[idx];
}


// -- public accessors --------------------------------------------------------

/* get size */
irc::message_list::size_type irc::message_list::size(void) const {
	// return size
	return _idx;
}


// -- public modifiers --------------------------------------------------------

/* append message */
void irc::message_list::append(const char* value, const irc::token::size_type size, const irc::token_type type) {
	// check if message list is empty
	if (_msgs.size() <= _idx) {
		// append message
		_msgs.push_back(message());
	} // append token to current message
	_msgs.back().append(value, size, type);
}

/* new message */
void irc::message_list::new_message(void) {
	// increment index
	++_idx;
}

/* clear */
void irc::message_list::clear(void) {
	// clear message list
	_msgs.clear();
	// reset index
	_idx = 0;
}




