#ifndef NE_H
#define NE_H
// modulo neg - eval
#include <iostream>
#include "lp.cpp"
#include "le.cpp"
#include "np.cpp"

template<typename T>
class NegEval : public T {
public:
    NegEval(ExpEval &expr) : T(expr){}

	virtual int eval() const override {
		return T::expr->eval() * -1;
	}
};

// Dei um nome para o Neg com funcionalidade de eval()
typedef NegEval<Neg<ExpEval<Exp>>> NegE;

//adiciona o teste da funcionalidade eval da exp Neg
template<typename T>
class TestNegEval : public T {
public:
    NegE ntree;

    TestNegEval() : ntree{T::ltree} {}

    void run() {
        T::run();
        std::cout << ntree.eval() << std::endl;
    }
};

#endif
