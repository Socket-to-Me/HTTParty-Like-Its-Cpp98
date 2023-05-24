#include "parser.hpp"

IRC::Parser::Parser(const Lexer& lexer)
: lexer(lexer), currentToken(lexer.getNextToken()) {

    return ;
}

void IRC::Parser::error(void) {
    
    throw std::runtime_error("Invalid syntax");
}

void IRC::Parser::eat(TokenType tokenType) {

    if (currentToken.type == tokenType) {

        currentToken = lexer.getNextToken();
    }
    else {
        error()
    }

    return ;
}

std::vector<std::string> IRC::Parser::parseParameters(void) {

    std::vector<std::string> parameters;

    while (currentToken.type == PARAMETER) {

        parameters.push_back(currentToken.value);
        eat(PARAMETER);
    }
    return parameters;
}

std::vector<std::string> IRC::Parser::parse(void) {

    std::vector<std::string> commands;
    while (currentToken.type != EOF_TOKEN) {

        if (currentToken.type == COMMAND) {

            eat(COMMAND);
            std::vector<std::string> parameters = parseParameters();
            std::stringstream ss;
            ss << currentToken.value;
            eat(COLON);

            while (currentToken.type != EOF_TOKEN) {

                ss << currentToken.value;
                eat(currentToken.type);
            }

            parameters.push_back(ss.str());
            commands.push_back(std::to_string(parameters.size()) + " parameters: " + ss.str());
        }

        eat(SPACE);
    }

    return commands;
}
