#ifndef NE_H
#define NE_H

// Module Neg - eval

#include <iostream>

// Implements eval method in Neg class
template<typename T>
class NegEval : public T {
public:

    // Constructor
    NegEval() = default;
    NegEval(Exp *expr){
        this->expr = expr;
    }

    // Eval implementation
	virtual int eval() override {
		return dynamic_cast<ExpEval<Exp>*>(T::expr)->eval() * -1;
	}

};

// Appends new functionality to Test class
template<typename T>
class TestNegEval : public T {
public:

    // Declares new version of ntree with eval functionality
    NegEval<Neg<ExpEval<Exp>>> ntree;

    // Constructor
    TestNegEval() : ntree{&(T::ltree)} {}

    // Appends to run method
    void run() {
        T::run();
        std::cout << ntree.eval() << std::endl;
    }
    
};

#endif
