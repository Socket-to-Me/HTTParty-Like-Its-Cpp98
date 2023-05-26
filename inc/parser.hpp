#include "lexer.hpp"

namespace IRC {

    class Parser {
            
        public:
        
            Parser(const Lexer& lexer);
            std::vector< std::vector< IRC::Token > > parse(void);

        private:

            Lexer   _lexer;
            Token   _currToken;
    };
}
