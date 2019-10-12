#ifndef AE_H
#define AE_H

// Module Add - eval

#include <iostream>

// Implements eval method in Add class
template<typename T>
class AddEval : public T {
public:
    
    // Constructor
    AddEval() = default;
    AddEval(Exp *left, Exp *right) {
        this->left = left;
        this->right = right;
    }

    // Eval implementation
    virtual int eval() override {
		return dynamic_cast<ExpEval<Exp>*>(T::left)->eval() 
        + dynamic_cast<ExpEval<Exp>*>(T::right)->eval();
	}

};

// Appends new functionality to Test class
template<typename T>
class TestAddEval : public T {
public:

    // Declares new version of atree with eval functionality
    AddEval<Add<ExpEval<Exp>>> atree;

    // Constructor
    TestAddEval() : atree{&(T::ltree), &(T::ltree)} {}

    // Appends to run method
    void run() {
        T::run();
        std::cout << atree.eval() << std::endl;
    }

};

#endif
