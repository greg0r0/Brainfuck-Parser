#include <iostream>
#include "parser.hpp"

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        std::cout << "Usage:" << argv[0] << " <BF source code file>" << std::endl;
        exit(1);
    }
    std::string source_code = ReadFile(argv[1]);
    auto l = Parser(Lexer(source_code));

    PrintTree(l, 0);

    l.Clear();
    return 0;
}
