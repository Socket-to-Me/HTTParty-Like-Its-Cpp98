#include "lexer.hpp"

IRC::Lexer::Lexer(const std::string& text)
: _text(text), _pos(0) {

	return ;
}

IRC::Token	IRC::Lexer::getNextToken(void) {

	while (_pos < _text.size()) {

		std::string	str;
		bool		err = false;

		if (isalpha(_text[_pos])) {

			bool		caps = true;

			while (isalpha(_text[_pos])) {

				if (islower(_text[_pos]))
					caps = false;
		
				str += _text[_pos];
				++_pos;
			}

			if (caps)
				return { COMMAND, str };

			return { PARAMETER, str };
		}

		if (_text[_pos] == ':') {

			str += _text[_pos++];

			while (_text[_pos] != '\r' && _text[_pos] != '\n' && _text[_pos] != '\0') {

				if (_text[_pos] == ':') 
					err = true;
				
				str += _text[_pos];
				++_pos;
			}

			if (err)
				return { ERROR, str };
			return { TRAILING, str };

		}

		if (_text[_pos] == ' ') {

			str += _text[_pos];
			++_pos;
			return { SPACE, str };
		}

		if (_text[_pos] == '\n') {

			str += _text[_pos];
			++_pos;
			return { NEWLINE, str };
		}
	
		if (_text[_pos] == '\r' && _text[_pos+1] == '\n') {

			++_pos;
			++_pos;
			return { EOF_TOKEN, "" };
		}

		while (_text[_pos] && _text[_pos] != '\r' && _text[_pos] != '\n') {

			if (_text[_pos] == ':') 
				err = true;
	
			str += _text[_pos];
			++_pos;
		}

		if (err)
			return { ERROR, str };
		return { TRAILING, str };

	}

	return { EOF_TOKEN, "" };
}
