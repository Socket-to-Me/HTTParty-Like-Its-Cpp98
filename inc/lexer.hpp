#include <iostream>
#include <string>
#include <vector>
#include <sstream>

enum TokenType {
    COMMAND,
    PARAMETER,
    COLON,
    SPACE,
    EOF_TOKEN
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    Lexer(const std::string& text) : text(text), pos(0) {}

    void error() {
        throw std::runtime_error("Invalid character");
    }

    void advance() {
        pos++;
    }

    char peek() {
        if (pos < text.size()) {
            return text[pos];
        }
        return '\0'; // End of text
    }

    Token getNextToken() {
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

private:
    std::string text;
    size_t pos;
};
