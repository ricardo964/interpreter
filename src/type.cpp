#include "./include/type.hpp"

Token::Token(token_type n_ttype, std::string n_lexeme)
{
    ttype = n_ttype;
    lexeme = n_lexeme;
}

std::string Token::get_lexeme() { return lexeme; };

token_type Token::get_type() { return ttype; }
