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

    struct Token {
    
        TokenType   type;
        std::string value;
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
