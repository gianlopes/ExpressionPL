#ifndef NP_H
#define NP_H

#include <iostream>
#include "lp.cpp"

template<typename T = Exp> //O template default é a classe Exp, mas pode-se usar qualquer uma
class Neg : public T {
public:	
	T *expr;
	
	Neg(T &e) : expr {&e} {}

	virtual void print(std::ostream &stream = std::cout) const override {
		stream << "-(";
		expr->print(stream);
		stream << ")";
	}
};

template<typename T>
class TestNeg : public T {
public:
    Neg<> ntree;

    TestNeg() : ntree{T::ltree} {}

    void run(){
        T::run();
    	ntree.print();
		std::cout << std::endl;
    }
};
#endif
