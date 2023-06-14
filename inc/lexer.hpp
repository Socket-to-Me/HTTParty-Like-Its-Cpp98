#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <array>


// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {


	// -- T O K E N -----------------------------------------------------------

    class token {


        public:

			// -- public types ------------------------------------------------

			/* size type */
			typedef std::string::size_type size_type;


			// -- public enums ------------------------------------------------

			/* token type */
			enum type {
				UNDEFINED_TOKEN,
				TAG_TOKEN,
				SOURCE_TOKEN,
				COMMAND_TOKEN,
				END_TOKEN,
				MAX_TOKEN_TYPE
			};


			// -- public constructors -----------------------------------------

			/* c-string and type constructor */
            token(const char*, const size_type, const type);

			/* string and type constructor */
			token(const std::string&, const type);

			/* copy constructor */
			token(const token&);

			/* destructor */
			~token(void);


			// -- public assignment operator ----------------------------------

			/* copy assignment operator */
			token& operator=(const token&);


			// -- public accessors --------------------------------------------

			/* get token value */
            const std::string& value(void) const;

			/* get token type */
            enum type type(void) const;


			// -- public setters ----------------------------------------------

			/* set token value */
			void value(const std::string&);

			/* set token value with c-string */
			void value(const char*, const size_type);

			/* set token type */
			void type(const enum type);


        private:

			// -- private members ---------------------------------------------

			/* token value */
			std::string _value;

			/* token type */
			enum type _type;

    };


	// -- T O K E N  T Y P E --------------------------------------------------

	/* token type helper */
	typedef enum token::type token_type;



	// -- M E S S A G E -------------------------------------------------------

	class message {


		public:

			// -- public types ------------------------------------------------

			/* size type */
			typedef std::vector<token>::size_type size_type;


			// -- public constructors -----------------------------------------

			/* default constructor */
			message(void);

			/* copy constructor */
			message(const message&);

			/* destructor */
			~message(void);


			// -- public assignment operator ----------------------------------

			/* copy assignment operator */
			message& operator=(const message&);


			// -- public subscript operator -----------------------------------

			/* subscript operator */
			const token& operator[](const size_type) const;


			// -- public accessors --------------------------------------------

			/* get vector size */
			size_type size(void) const;


			// -- public modifiers --------------------------------------------

			/* append token */
			void append(const token&);

			/* append token with c-string value and type */
			void append(const char*, const token::size_type, const token_type);

			/* append token with string value and type */
			void append(const std::string&, const token_type);


		private:

			// -- private members ---------------------------------------------

			/* token vector */
			std::vector<token> _tokens;

	};


	// -- M E S S A G E  L I S T ----------------------------------------------

	/* message vector type */
	typedef std::vector<message> message_list;




	// -- L E X E R  S T A T E ------------------------------------------------

	enum lexer_state {
		DEFAULT_STATE,
		TAG_STATE,
		SOURCE_STATE,
		COMMAND_STATE,
		MAX_LEXER_STATE
	};


	// -- C H A R  T Y P E ----------------------------------------------------

	enum char_type {
		NULL_CHAR,       // \0
		CTRL_CHAR,       // \1 - \31 (except \n and \r)

		OTHER_CHAR,      // all other characters
		COLON_CHAR,      // :
		AT_CHAR,         // @

		SPACE_CHAR,      // ' '
		NL_CHAR,         // \n
		CR_CHAR,         // \r

		MAX_CHAR_TYPE
	};


	// -- L E X E R  A C T I O N ----------------------------------------------

	enum lexer_action {
		SKIP,
		COUNT,
		APPEND,
		END_OF_MESSAGE,
		MAX_LEXER_ACTION
	};


	// -- L E X E R -----------------------------------------------------------

	class lexer {

        // treating UTF8 need to take in char as unsigned char
        char_type   get_char_type(uint8_t c);

		struct transition {
			lexer_state		state;
			lexer_action	action;
		};

		public:

			// -- public static methods ---------------------------------------

			/* static lex */
			static void lex(message_list&, const std::string&);


		private:

			// -- private constructors ----------------------------------------

			/* default constructor */
			lexer(message_list&, const std::string&);

			/* copy constructor */
			lexer(const lexer&);

			/* destructor */
			~lexer(void);


			// -- private methods ---------------------------------------------

			/* lex */
			void lex(void);

			/* skip action */
			void skip(void);

			/* count action */
			void count(void);

			/* append action */
			void append(void);

			/* end of message action */
			void end_of_message(void);






			// -- T R A N S I T I O N -----------------------------------------

			class transition {

				public:

					// -- public constructors ---------------------------------

					/* members constructors */
					transition(const lexer_state, const token_type, const lexer_action);

					/* copy constructor */
					transition(const transition&);

					/* destructor */
					~transition(void);


					// -- public assignment operator --------------------------

					/* copy assignment operator */
					transition& operator=(const transition&);


					// -- public accessors ------------------------------------

					/* get lexer state */
					lexer_state state(void) const;

					/* get token type */
					token_type type(void) const;

					/* get lexer action */
					lexer_action action(void) const;


				private:

					// -- private members -------------------------------------

					/* state */
					lexer_state _state;

					/* token type */
					token_type _type;

					/* action */
					lexer_action _action;

			};


			// -- private types -----------------------------------------------

			/* lookup table type */
			typedef std::array<std::array<transition,
					           MAX_CHAR_TYPE>,
					MAX_LEXER_STATE> table;

			/* action prototype */
			typedef void(lexer::*proto)(void);

			/* action table type */
			typedef std::array<proto, MAX_LEXER_ACTION> action;

			/* char table type */
			typedef std::array<char_type, 256> char_table;

			/* size type */
			typedef std::string::size_type size_type;

			/* state debug type */
			typedef std::array<std::string, MAX_LEXER_STATE> state_debug;

			/* action debug type */
			typedef std::array<std::string, MAX_LEXER_ACTION> action_debug;

			/* char debug type */
			typedef std::array<std::string, MAX_CHAR_TYPE> char_debug;


			// -- private members ---------------------------------------------

			/* message list reference */
			message_list&      _msgs;

			/* string to lex reference */
			const std::string& _str;

			/* index */
			size_type          _idx;

			/* counter */
			std::size_t        _count;

			/* transition */
			transition         _transition;


			// -- private static members --------------------------------------

			/* lookup table */
			static const table _lookup;

			/* action table */
			static const action _actions;

			/* char table */
			static const char_table _chars;

			/* state debug */
			static const state_debug _state_debug;

			/* action debug */
			static const action_debug _action_debug;

			/* char debug */
			static const char_debug _char_debug;





	};


}
