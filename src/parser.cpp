#include "parser.hpp"

IRC::Parser::Parser(const Lexer& lexer)
: _lexer(lexer), _currToken(_lexer.getNextToken()) {

    return ;
}

std::vector<std::string> IRC::Parser::parse(void) {

    std::vector<std::string> cmd;

    while (_currToken.type != EOF_TOKEN) {

        while (_currToken.type != NEWLINE && _currToken.type != EOF_TOKEN) {

            cmd.push_back(_currToken.value);
        }

        for (const auto& element : cmd)
            std::cout << element << std::endl;
    }

    return cmd;
}
