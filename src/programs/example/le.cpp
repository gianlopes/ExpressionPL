#ifndef LE_H
#define LE_H
// modulo lit - eval
#include <iostream>

// This file is nearly equal to src/le.cpp, the only difference
// is that we removed the include for src/lp.cpp as the Lit class
// and print method are going to be implemented separately for this example.

// Adds eval method to an interface
template<typename T = Exp>
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

    // Eval implementation
    virtual int eval() const override {
		return T::value;
	}
    
};

// Appends new functionality to Test class
template<typename T>
class TestLitEval : public T {
public:

    // Declares new version of ltree with print functionality
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
