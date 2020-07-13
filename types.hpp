#ifndef AST_TYPES_H
#define AST_TYPES_H
#include <vector>

//Elements of BF syntax, for lexer parser
enum class Token {
    t_INCREASE    = '+',
    t_DECREASE    = '-', 
    t_SHIFT_LEFT  = '<', 
    t_SHIFT_RIGHT = '>', 
    t_LOOP_OPEN   = '[', 
    t_LOOP_CLOSE  = ']', 
    t_INPUT       = ',', 
    t_OUTPUT      = '.'
};


class Command {
private:
    Token _Token;
public:
    Command() {}
    Command(Token t) :_Token(t) {} 
    Token getToken() { return this->_Token; }
};

class Loop : public Command {
private:
    Token _Token;
    std::vector<Command> _Commands;
public:
    std::vector<Command> getCommands() { return this->_Commands;}
};

#endif