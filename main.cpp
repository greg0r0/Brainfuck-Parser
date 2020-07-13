#include <iostream>
#include <sstream>
#include <fstream>
#include "types.hpp"

/*
  main functionality
*/
std::vector<Token>   Lexer(std::string);
std::vector<Command> Parser(std::vector<Token>);
void                 BuildXML(std::vector<Command>);

/*
    util functions
*/
std::string ReadFile(char*);



int main(int argc, char* argv[]) {
    
    if ( argc != 2 ){
        std::cout << "Usage:" << argv[0] << " <BF source code file>" << std::endl;
        exit(1);
    }
    std::string source_code = ReadFile(argv[1]);
    auto k = Lexer(source_code);

    return 0;
}


std::string ReadFile(char* source_file){
    std::ifstream bf_source(source_file);
    std::stringstream buffer;

    if (bf_source.is_open()) {
        buffer << bf_source.rdbuf();
    } else {
        std::cerr << "[!] Error: Source Code File can't be open." << std::endl;
        exit(1);
    }

    return buffer.str();
}

//Lexer for brainfuck is simple -- just split all chars to token vector
std::vector<Token> Lexer(std::string source){
    std::vector<Token> result;

    for (auto c: source){
        try{
            result.push_back((Token)c);
        } catch (...) {
            //Brainfuck ignoring non-syntax characters - try-catch for enum type cast errors
        }
    }

    return result;
}