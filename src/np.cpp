#ifndef NP_H
#define NP_H

// Module Neg - print

#include <iostream>

// Defines the Neg class
// It implements method print from interface Exp
template<typename T>
class Neg : public T {
public:

	// Stores an expression
	Exp *expr;
	
	// Constructor
	Neg() = default;
	Neg(Exp *e) : expr{e} {}

	// Print implemantation, defaults output to std::cout
	virtual void print(std::ostream &stream = std::cout) const override {
		stream << "-(";
		expr->print(stream);
		stream << ")";
	}

};

// Appends new functionality to Test class
template<typename T>
class TestNeg : public T {
public:

    Neg<Exp> ntree;

	// Constructor
    TestNeg() : ntree{&(T::ltree)} {}

	// Appends to method run
    void run(){
        T::run();
    	ntree.print();
		std::cout << std::endl;
    }

};

#endif
