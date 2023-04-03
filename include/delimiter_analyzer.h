#pragma once
#include "stack.h"
#include <string>
#include <fstream>

namespace ssuds
{
class DelimiterAnalyzer
{
public:
    enum class TokenType {PAREN, SQUARE, CURLY};
    class Token
    {
    public:
        Token(TokenType T, int num, int pos);
        TokenType type;
        int line_num;
        int char_pos;
    };

    std::fstream file;
    DelimiterAnalyzer(std::string fname);
    void process();

protected:
    ssuds::Stack<Token> mTokenStack;
    bool is_opening(char c);
    bool closing_matches(char c, TokenType opening_type);
};
}