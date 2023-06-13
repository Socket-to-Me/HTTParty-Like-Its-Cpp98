#include "lexer.hpp"

IRC::Token::Token(TokenType type, const std::string& value)
: _type(type), _value(value) 
{
	return ;
}

IRC::TokenType               IRC::Token::getType(void) const
{
	return _type;
}

const std::string&      IRC::Token::getValue(void) const
{
	return _value;
}

IRC::Lexer::Lexer(const std::string& text)
: _text(text), _pos(0) {

	return ;
}

IRC::Token	IRC::Lexer::getNextToken(void) {

	while (_pos < _text.size()) {

		std::string	str;
		bool		err = false;

		// ----- C O M M A N D ------------------------------------

		if (isalpha(_text[_pos])) {

			bool		caps = true;

			while (isalpha(_text[_pos])) {

				if (islower(_text[_pos]))
					caps = false;
		
				str += _text[_pos];
				++_pos;
			}

			if (caps)
				return Token(COMMAND, str);

			return Token(PARAMETER, str);
		}

		// ----- T R A I L I N G ------------------------------------

		if (_text[_pos] == ':') {

			str += _text[_pos++];

			while (_text[_pos] && _text[_pos] != '\r' && _text[_pos] != '\n' && _text[_pos] != '\0') {

				if (_text[_pos] == ':') 
					err = true;
				
				str += _text[_pos];
				++_pos;
			}

			if (err)
				return Token(ERROR, str);
			return Token(TRAILING, str);

		}

		// ----- S P A C E ------------------------------------

		if (_text[_pos] == ' ') {

			str += _text[_pos];
			++_pos;
			return Token(SPACE, str);
		}

		// ----- N E W  L I N E ------------------------------------

		if (_text[_pos] == '\n') {

			str += _text[_pos];
			++_pos;
			return Token(NEWLINE, str);
		}
	
		// ----- E O F ------------------------------------

		if (_text[_pos] == '\r' && _text[_pos+1] == '\n') {

			++_pos;
			++_pos;
			return Token(EOF_TOKEN, "");
		}

		// ----- P A R A M E T E R S ------------------------------------

		while (_text[_pos] && _text[_pos] != ' ' && _text[_pos] != '\r' && _text[_pos] != '\n') {

			if (_text[_pos] == ':') 
				err = true;
	
			str += _text[_pos];
			++_pos;
		}

		if (err)
			return Token(ERROR, str);
		return Token(PARAMETER, str);
	}

	return Token(EOF_TOKEN, "");
}
