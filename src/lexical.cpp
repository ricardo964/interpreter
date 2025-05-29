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

std::vector<Token> Lexer::get_tokens() { return tokens; }

char Lexer::next_character()
{
    end += 1;
    return source[end - 1];
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

std::string Lexer::dfa_number(char character)
{
    char current_character = character;
    std::string lexeme;
    while (true)
    {
        if (!(is_digit(current_character) || current_character == '.'))
            break;
        lexeme += current_character;
        current_character = next_character();
    }

    return lexeme;
}

std::string Lexer::dfa_identifier(char character)
{
    char current_character = character;
    std::string lexeme;
    while (true)
    {
        if (!is_character(current_character))
            break;
        lexeme += current_character;
        current_character = next_character();
    }

    return lexeme;
}

std::vector<Token> Lexer::tokenizer(std::string new_source)
{
    source += new_source;
    while (end < source.size())
    {
        char character = next_character();

        if (is_character(character))
        {
            std::string lexeme_id = dfa_identifier(character);
            tokens.push_back(
                Token(token_type::IDENTIFIER, lexeme_id));
            end--;
            continue;
        }

        if (is_digit(character))
        {
            std::string lexeme_id = dfa_number(character);
            tokens.push_back(
                Token(token_type::NUMBER, lexeme_id));
            end--;
            continue;
        }

        switch (character)
        {
        case '=':
            tokens.push_back(
                Token(token_type::EGUAL, std::string(1, character)));
            forward_to_end();
            break;

        case '+':
            tokens.push_back(
                Token(token_type::PLUS, std::string(1, character)));
            forward_to_end();
            break;

        case '-':
            tokens.push_back(
                Token(token_type::MINUS, std::string(1, character)));
            forward_to_end();
            break;

        case '*':
            tokens.push_back(
                Token(token_type::STAR, std::string(1, character)));
            forward_to_end();
            break;

        case '/':
            tokens.push_back(
                Token(token_type::LBAR, std::string(1, character)));
            forward_to_end();
            break;
        default:
            break;
        }

        forward_to_end();
    }

    return tokens;
}
