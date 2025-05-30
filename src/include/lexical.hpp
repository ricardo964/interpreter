#ifndef _LEXICAL_
#define _LEXICAL_

#include <iostream>
#include <vector>
#include <string>
#include <cinttypes>
#include "type.hpp"

class Lexer
{
private:
    std::vector<Token> tokens;
    std::string source;
    std::uint64_t forward, end;

public:
    Lexer();

    void next();
    std::vector<Token> get_tokens();
    char get_character();
    void forward_to_end();
    bool is_character(char character);
    bool is_digit(char character);
    std::string dfa_number();
    std::string dfa_identifier();
    std::vector<Token> tokenizer(std::string new_source); 
};

#endif