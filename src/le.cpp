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

    // Declares new version of ltree with eval functionality
    LitEval<Lit<ExpEval<Exp>>> ltree;
    
    // Constructor
    TestLitEval() : ltree{T::ltree.value} {}

    // Appends to run method
    void run() {
        T::run();
        std::cout << ltree.eval() << std::endl;
    }

};

#endif
