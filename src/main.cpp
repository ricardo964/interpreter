#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cinttypes>

#include "include/type.hpp"
#include "include/lexical.hpp"

int main(int argc, char **argv)
{
    Lexer lex;
    while (true)
    {
        std::string buffer;
        std::cout << "-> ";
        std::getline(std::cin, buffer);
        lex.tokenizer(buffer);
        lex.print_tokens();
    }

    return 0;
}