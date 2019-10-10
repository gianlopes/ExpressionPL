#ifndef PRINT_H
#define PRINT_H

// This module is used to add print functionality to lit.cpp

#include <iostream>
#include "lit.cpp"

// Adds print method to an interface
template <typename T = Exp>
class ExpPrint : public T{
public:

	// Appends astract method print
	virtual void print(std::ostream &stream = std::cout) const = 0;

};

// Implements print method in Lit class
template<typename T>
class LitPrint : public T {
public:

	// Constructor
	LitPrint(int v) : T(v) {}

	// Print implemantation, defaults output to std::cout
	virtual void print(std::ostream &stream = std::cout) const override {
		stream << T::value;
	}

};

// Appends new functionality to Test class
template<typename T>
class TestLitPrint : public T {
public:

	// Declares new version of ltree with print functionality
	LitPrint<Lit<ExpPrint<Exp>>> ltree;

	// Constructor
	TestLitPrint() : ltree{T::ltree.value} {} 

	// Appends to run method
	void run() {
		T::run();
		ltree.print();
		std::cout << std::endl;
	}
	
};

#endif
