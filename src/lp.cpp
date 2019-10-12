#ifndef LP_H
#define LP_H

// Module Lit - print

#include <iostream>

// Creates interface Exp containing the print method.
class Exp {
public:

	// Abstract method print
	virtual void print(std::ostream &stream = std::cout) const = 0;

};

// The Lit class represents a Literal and simply stores a value.
// It implements method print from interface Exp
template<typename T = Exp> // Default template is Exp
class Lit : public T {
public:

	int value;

	// Constructor
	Lit() = default;
	Lit(int v) : value{v} {};
	
	// Print implemantation, defaults output to std::cout
	virtual void print(std::ostream &stream = std::cout) const override {
		stream << value;
	}

};

// Test class - used in the article to test module compositions
class TestLit {
public:

	// In object creation, all Interfaces should be inherited before adding the classes.
	Lit<Exp> ltree;

	// Constructor
	TestLit() : ltree{3} {} 

	// Declares method to run the test
	void run() {
		ltree.print();
		std::cout << std::endl;
	}
};

#endif
