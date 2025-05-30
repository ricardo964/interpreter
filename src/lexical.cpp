#include <iostream>
#include <vector>
#include <string>
#include <cinttypes>

#include "include/type.hpp"
#include "include/lexical.hpp"

Lexer::Lexer()
{
    forward = 0;
    end = 0;
}

std::vector<Token> Lexer::get_tokens()
{
    return tokens;
}

void Lexer::next()
{
    end += 1;
}

char Lexer::get_character()
{
    return source[end];
}

void Lexer::forward_to_end()
{
    forward = end;
}

bool Lexer::is_character(char character)
{
    if ((character >= 65 and character <= 90) or (character >= 97 and character <= 122))
        return true;
    return false;
}

bool Lexer::is_digit(char character)
{
    if (character >= 48 and character <= 57)
        return true;
    return false;
}

std::string Lexer::dfa_number()
{
    std::string lexeme;

    for (
        char character = get_character();
        is_digit(character) or character == '.';
        character = get_character())
    {
        lexeme += character;
        next();
    }

    return lexeme;
}

std::string Lexer::dfa_identifier()
{
    std::string lexeme;

    for (
        char character = get_character();
        is_character(character) or character == '_';
        character = get_character())
    {
        lexeme += character;
        next();
    }

    return lexeme;
}

std::vector<Token> Lexer::tokenizer(std::string new_source)
{
    source += new_source;
    while (end < source.size())
    {
        char character = get_character();

        if (is_character(character))
        {
            std::string lexeme = dfa_identifier();
            tokens.push_back(
                Token(token_type::IDENTIFIER, lexeme));
            forward_to_end();
            continue;
        }

        if (is_digit(character))
        {
            std::string lexeme = dfa_number();
            tokens.push_back(
                Token(token_type::NUMBER, lexeme));
            forward_to_end();
            continue;
        }

        switch (character)
        {
        case ' ':
            break;

        case '\n':
            break;

        case '\t':
            break;

        case '=':
            tokens.push_back(
                Token(token_type::EGUAL, std::string(1, character)));
            break;

        case '+':
            tokens.push_back(
                Token(token_type::PLUS, std::string(1, character)));
            break;

        case '-':
            tokens.push_back(
                Token(token_type::MINUS, std::string(1, character)));
            break;

        case '*':
            tokens.push_back(
                Token(token_type::STAR, std::string(1, character)));
            break;

        case '/':
            tokens.push_back(
                Token(token_type::LBAR, std::string(1, character)));
            break;
        default:
            std::cout << "invalid character " << character << std::endl;
            break;
        }

        next();
        forward_to_end();
    }

    return tokens;
}
