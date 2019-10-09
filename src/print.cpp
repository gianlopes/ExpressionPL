#ifndef PRINT_H
#define PRINT_H

// Module Lit - print

#include <iostream>
#include "lit.cpp"

// This module creates interface Exp containing the print method.
template <typename T>
class ExpPrint : public T{
public:
	virtual void print(std::ostream &stream = std::cout) const = 0;
};

// The Lit class that can implement Exp print method
// and is used to represent an Int literal.
template<typename T = Exp> // Default template is Exp
class Lit : public T {
public:
	// Print implemantation, defaults output to std::cout
	virtual void print(std::ostream &stream = std::cout) const override {
		stream << value;
	}
};

// Test class - used in the article to test module compositions
class TestLit {
public:
	Lit<> ltree;
	TestLit() : ltree{3} {} 

	void run() {
		ltree.print();
		std::cout << std::endl;
	}
};

#endif
