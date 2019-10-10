#ifndef LIT_H
#define LIT_H

#include <iostream>

// This module creates interface Exp containing the print method.
class Exp {
};

// The Lit class that can implement Exp print method
// and is used to represent an Int literal.
template<typename T = Exp> // Default template is Exp
class Lit : public T {
public:
	int value;

	Lit(int v) : value{v} {};
};

// Test class - used in the article to test module compositions
class TestLit {
public:
	Lit<> ltree;
	TestLit() : ltree{3} {} 
    void run() {
    }
};


#endif