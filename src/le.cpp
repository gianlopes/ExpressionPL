#ifndef LE_H
#define LE_H
// modulo lit - eval
#include <iostream>
#include "lp.cpp"

//adiciona a funcionalidade eval a interface exp
template<typename T = Exp>
class ExpEval : public T {
public:

    virtual int eval() const = 0;
};

//adiciona a funcionalidade eval ao lit
template<typename T>
class LitEval : public T {
public:
    LitEval(int v) : T(v) {}

    virtual int eval() const override {
		return T::value;
	}
};

// Dei um nome para o Lit com funcionalidade de eval()
typedef LitEval<Lit<ExpEval<Exp>>> LitE;

//adiciona o teste da funcionalidade eval
template<typename T>
class TestLitEval : public T {
public:
    LitE ltree;
    TestLitEval() : ltree{T::ltree.value} {}

    void run() {
        T::run();
        std::cout << ltree.eval() << std::endl;
    }
};

#endif
