#ifndef AP_H
#define AP_H

// Module Add - print

#include <iostream>

// Defines the Add class
// It implements method print from interface Exp
template<typename T>
class Add : public T {
public:

	// Stores left and right expression references
	Exp *left;
	Exp *right;

	// Constructor
	Add() = default;
	Add(Exp *l, Exp *r) : left{l}, right{r} {}

	// Print implemantation, defaults output to std::cout
    virtual void print(std::ostream &stream = std::cout) const override {
		left->print(stream);
		stream << '+';
		right->print(stream);
	}

};

// Appends new functionality to Test class
template<typename T>
class TestAdd : public T {
public:

    Add<Exp> atree;

	// Constructor
    TestAdd() : atree{&(T::ltree), &(T::ltree)} {}

	// Appends to method run
    void run(){
        T::run();
    	atree.print();
		std::cout << std::endl;
    }

};

#endif
