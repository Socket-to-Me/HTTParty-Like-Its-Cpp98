#include <iostream>
#include <string>
#include <vector>
#include <sstream>

namespace IRC {

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
            Lexer(const std::string& text);
            void advance();
            char peek();
            Token getNextToken();

        private:
            std::string text;
            size_t pos;
    };

}

