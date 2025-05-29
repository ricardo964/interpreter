#ifndef _TYPE_I_
#define _TYPE_I_

#include <iostream>
#include <string>
#include <cinttypes>

enum class token_type
{
    // reserved words
    IDENTIFIER,

    // operator
    EGUAL,
    PLUS,
    MINUS,
    STAR,
    LBAR,

    // value
    NUMBER,
    UNKWON
};

class Token
{
private:
    // bad implementation
    token_type ttype;
    std::string lexeme;
public:
    Token(token_type n_ttype, std::string n_lexeme);
    std::string get_lexeme();
    token_type get_type();
};

#endif