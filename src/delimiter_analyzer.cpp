#include "delimiter_analyzer.h"
#include "stack.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

ssuds::DelimiterAnalyzer::Token::Token()
{
    //default
}

ssuds::DelimiterAnalyzer::Token::Token(TokenType T, int num, int pos)
{
    type = T;
    char_pos = pos;
    line_num = num;
}

ssuds::DelimiterAnalyzer::DelimiterAnalyzer(std::string fname)
{
    mTokenStack.clear();
    file = std::fstream(fname, std::ios::out);
}

std::string ssuds::DelimiterAnalyzer::process()
{
    int j = 0;
    std::string cur_line;
    std::ostringstream output;
    while(!file.eof())
    {
        std::getline(file, cur_line);
        for(int i = 0; i < cur_line.size(); i++)
        {
            if(cur_line[i] != '(' && cur_line[i] != ')' &&
            cur_line[i] != '[' && cur_line[i] != ']' &&
            cur_line[i] != '{' && cur_line[i] != '}')
                continue;
            else
            {
                if(is_opening(cur_line[i]))
                {
                    TokenType token;
                    if(cur_line[i] == '(')
                        token = TokenType::PAREN;
                    else if(cur_line[i] == '{')
                        token = TokenType::CURLY;
                    else
                        token = TokenType::SQUARE;
                    Token new_token(token, i, i);
                    mTokenStack.push(new_token);
                }

                else if(closing_matches(cur_line[i], mTokenStack.top().type))
                {
                    mTokenStack.pop();
                }

                else if(!closing_matches(cur_line[i], mTokenStack.top().type))
                {
                    output << "Mismatched tokens at position: " << i 
                    << ", and on line: " << j << std::endl;
                }
            }
        }
        j++;
    }

    if(!mTokenStack.empty())
        output << "Mismatched tokens. Opening token, but no closing token." << std::endl;
    else
        output << "All good!" << std::endl;
    return output.str();
}

bool ssuds::DelimiterAnalyzer::is_opening(char c)
{
    if(c == '(')
        return true;
    else if(c == '[')
        return true;
    else if(c == '{')
        return true;
    else
        return false;
}

bool ssuds::DelimiterAnalyzer::closing_matches(char c, TokenType opening_type)
{
    if(opening_type == TokenType::PAREN && c == ')')
        return true;
    else if(opening_type == TokenType::CURLY && c == '}')
        return true;
    else if(opening_type == TokenType::SQUARE && c == ']')
        return true;
    else
        return false;
}