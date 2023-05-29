#include "parser.hpp"

IRC::Parser::Parser(const Lexer& lexer)
: _lexer(lexer), _currToken(_lexer.getNextToken()) {

    return ;
}

std::vector< std::vector< IRC::Token > > IRC::Parser::parse(void) {

    std::vector< std::vector< Token > > matrix;
    std::vector<Token> cmd;

    while (_currToken.type != EOF_TOKEN) {

        while (_currToken.type != NEWLINE && _currToken.type != EOF_TOKEN) {

            cmd.push_back(_currToken);
            _currToken = _lexer.getNextToken();

        }

        matrix.push_back(cmd);
        cmd.clear();
        _currToken = _lexer.getNextToken();

    }

    return matrix;
}
