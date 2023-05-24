#include "lexer.hpp"

class Parser {
        
    public:
    
        Parser(const Lexer& lexer);
        void error(void);
        void eat(TokenType tokenType);
        std::vector<std::string> parseParameters(void);
        std::vector<std::string> parse(void);

    private:

        Lexer lexer;
        Token currentToken;
};
