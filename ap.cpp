#ifndef AP_H
#define AP_H

#include <iostream>
#include "lp.cpp"

template<typename T = Exp> //O template default é a classe Exp, mas pode-se usar qualquer uma
class Add : public T {
public:
	const T *left;
	const T *right;
	Add(T &l, T &r) : left{&l}, right{&r} {}

    virtual void print() const override {
		left->print();
		std::cout << '+';
		right->print();
	}

};

template<typename T>
class TestAdd : public T {
public:
    Add<> atree;

    TestAdd() : atree{T::ltree, T::ltree} {}

    void run(){
        T::run();
    	atree.print();
		std::cout << std::endl;
    }

};

#endif
