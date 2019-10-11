#ifndef LE_H
#define LE_H

// Module Lit - eval

#include <iostream>

// Adds eval method to an interface
template<typename T>
class ExpEval : public T {
public:

    // Appends abstract method eval
    virtual int eval() const = 0;

};

// Implements eval method in Lit class
template<typename T>
class LitEval : public T {
public:

    // Constructor
    LitEval(int v) : T(v) {}

    // Eval implemantation
    virtual int eval() const override {
		return T::value;
	}

};

// Appends new functionality to Test class
template<typename T>
class TestLitEval : public T {
public:

    // In object creation, all Interfaces should be inherited before adding the classes: Can't do LitEval<ExpEval<Lit<Exp>>>
    // Also, class deltas should never be inherited before the class defition : Can't do LitEval<ExpEval> nor Lit<LitEval<ExpEval<Exp>>>
    LitEval<Lit<ExpEval<Exp>>> ltree; // Declares new version of ltree with eval functionality
    
    // Constructor
    TestLitEval() : ltree{T::ltree.value} {}

    // Appends to run method
    void run() {
        T::run();
        std::cout << ltree.eval() << std::endl;
    }

};

#endif
