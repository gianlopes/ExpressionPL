#ifndef PRINT_H
#define PRINT_H

// Module Lit - print

#include <iostream>
#include "lit.cpp"

// This module creates interface Exp containing the print method.
template <typename T = Exp>
class ExpPrint : public T{
public:
	virtual void print(std::ostream &stream = std::cout) const = 0;
};

// The Lit class that can implement Exp print method
// and is used to represent an Int literal.
template<typename T> // Default template is Exp
class LitPrint : public T {
public:
	LitPrint(int v) : T(v) {}
	// Print implemantation, defaults output to std::cout
	virtual void print(std::ostream &stream = std::cout) const override {
		stream << T::value;
	}
};

// Test class - used in the article to test module compositions
template<typename T>
class TestLitPrint : public T {
public:
	LitPrint<Lit<ExpPrint<Exp>>> ltree;
	TestLitPrint() : ltree{T::ltree.value} {} 

	void run() {
		T::run();
		ltree.print();
		std::cout << std::endl;
	}
};

#endif
