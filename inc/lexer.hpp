#include <iostream>
#include <string>
#include <vector>
#include <sstream>

namespace IRC {

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
