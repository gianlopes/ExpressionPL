#include <iostream>

//Interface Exp
class Exp {
public:
    virtual void print() = 0;
    virtual int eval() = 0;
};