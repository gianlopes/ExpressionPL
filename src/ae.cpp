#ifndef AE_H
#define AE_H

// Module Add - eval

#include <iostream>

// Implements eval method in Add class
template<typename T>
class AddEval : public T {
public:
    
    // Constructor
    AddEval(ExpEval<Exp> &left, ExpEval<Exp> &right) : T(left, right){}

    // Eval implementation
    virtual int eval() const override {
		return T::left->eval() + T::right->eval();
	}

};

// Appends new functionality to Test class
template<typename T>
class TestAddEval : public T {
public:

    // Declares new version of atree with eval functionality
    AddEval<Add<ExpEval<Exp>>> atree;

    // Constructor
    TestAddEval() : atree{T::ltree, T::ltree} {}

    // Appends to run method
    void run() {
        T::run();
        std::cout << atree.eval() << std::endl;
    }

};

#endif
