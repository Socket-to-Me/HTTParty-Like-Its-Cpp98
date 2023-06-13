#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <array>

namespace IRC {

	enum token_type {

		MAX_TOKEN_TYPE
	};

	enum lexer_state {

		DEFAULT,

		IN_TAG,

		IN_SOURCE,

		START_CMD,
		IN_CMD,


		MAX_LEXER_STATE
	};


	enum char_type {

		AT,                 // @
		COLON, // :
		SPACE, // ' '
		NEWLINE, // \n
		CARRIAGE_RETURN, // \r
		OTHER, // all other characters
		MAX_CHAR_TYPE
	};

	enum lexer_action {
		SKIP,
		CATCH,
		MAX_LEXER_ACTION
	};


	class lexer {

        // treating UTF8 need to take in char as unsigned char
        char_type   getCharType(uint8_t c);

		struct transition {
			lexer_state		state;
			lexer_action	action;
		};

		std::array<std::array<transition,
							MAX_CHAR_TYPE>,
				MAX_LEXER_STATE> _lookup = {

			// -- D E F A U L T  S T A T E ----------------------------------------

				{ IN_TAG, SKIP },  // AT
				{ DEFAULT, SKIP }, // COLON
				{ DEFAULT, SKIP }, // SPACE
				{ DEFAULT, SKIP }, // NEWLINE
				{ DEFAULT, SKIP }, // CARRIAGE_RETURN
				{ DEFAULT, SKIP }  // OTHER
		};



		transition trans = _lookup[current_state][current_char];

	};








    enum TokenType {

        COMMAND,
        SPACE,
        PARAMETER,
        TRAILING,
        NEWLINE,
        EOF_TOKEN,
        ERROR
    };

    class Token {

        public:
            Token(TokenType type, const std::string& value);
            TokenType               getType(void) const;
            const std::string&      getValue(void) const;

        private:
            TokenType       _type;
            std::string     _value;
    };

    class Lexer {

        public:
            Lexer(const std::string& text);
            Token getNextToken();

        private:
            std::string _text;
            size_t      _pos;
    };

}
