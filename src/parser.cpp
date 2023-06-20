#include "parser.hpp"

//irc::Parser::Parser(const Lexer& lexer)
//: _lexer(lexer), _currToken(_lexer.getNextToken()) {
//
//    return ;
//}
//
//std::vector< std::vector< irc::Token > > irc::Parser::parse(void) {
//
//    std::vector< std::vector< Token > > matrix;
//    std::vector<Token> cmd;
//
//    while (_currToken.getType() != EOF_TOKEN) {
//
//        while (_currToken.getType() != NEWLINE && _currToken.getType() != EOF_TOKEN) {
//
//            cmd.push_back(_currToken);
//            _currToken = _lexer.getNextToken();
//
//        }
//
//        matrix.push_back(cmd);
//        cmd.clear();
//        _currToken = _lexer.getNextToken();
//
//    }
//
//    return matrix;
//}
