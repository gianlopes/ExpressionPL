#ifndef AE_H
#define AE_H
//modulo add - eval
#include <iostream>
#include "lp.cpp"
#include "ap.cpp"
#include "le.cpp"

//adiciona a funcionalidade eval ao Add
template<typename T>
class AddEval : public T {
public:
    AddEval(LitE &left, LitE &right) : T(left, right){}

    virtual int eval() const override {
		return T::left->eval() + T::right->eval();
	}
};

// Dei um nome para o add com funcionalidade de eval()
typedef AddEval<Add<ExpEval<Exp>>> AddE;

//adiciona o teste da funcionalidade eval
template<typename T>
class TestAddEval : public T {
public:
    AddE atree;
    TestAddEval() : atree{T::ltree, T::ltree} {}

    void run() {
        T::run();
        std::cout << atree.eval() << std::endl;
    }
};
#endif
