#ifndef LIT_H
#define LIT_H

// This module Creates our interface and type without the print method

#include <iostream>

// This module creates interface Exp that is empty
class Exp {
};

// The Lit class represents a Literal and simply stores a value.
template<typename T = Exp>
class Lit : public T {
public:
	int value;

	// Constructor
	Lit(int v) : value{v} {};

};

// Test class - used in the article to test module compositions
class TestLit {
public:

	// Creates a Lit called ltree
	Lit<Exp> ltree;

	// Constructor
	TestLit() : ltree{3} {} 
    
	// Empty run method
	void run() {
    }

};


#endif