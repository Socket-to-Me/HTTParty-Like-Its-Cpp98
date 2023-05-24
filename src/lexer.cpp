#include "lexer.hpp"

IRC::Lexer::Lexer(const std::string& text)
: text(text), pos(0) {

	return ;
}

void IRC::Lexer::advance(void) {
	
	pos++;
	return ;
}

char IRC::Lexer::peek(void) {

	if (pos < text.size()) {
		return text[pos];
	}
	return '\0'; // End of text
}

Token IRC::Lexer::getNextToken(void) {

	while (pos < text.size()) {
		char currentChar = text[pos];

		if (currentChar == '/') {

			std::string command;
			advance();

			while (isalpha(peek())) {
				command += peek();
				advance();
			}
			return { COMMAND, command };
		}

		if (currentChar == ':') {

			advance();
			return { COLON, ":" };
		}

		if (currentChar == ' ') {

			advance();
			return { SPACE, " " };
		}

		if (currentChar == '\r' && peek() == '\n') {

			advance();
			advance();
			return { EOF_TOKEN, "" };
		}

		if (currentChar == '\n') {

			advance();
			return { EOF_TOKEN, "" };
		}

		std::string parameter;
		while (peek() != ' ' && peek() != '\r' && peek() != '\n' && peek() != '\0') {

			parameter += peek();
			advance();
		}

		return { PARAMETER, parameter };
	}

	return { EOF_TOKEN, "" };
}
