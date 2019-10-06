#ifndef LP_H
#define LP_H
//modulo lit - print
#include <iostream>

//Interface Exp
class Exp {
public:
	virtual void print(std::ostream &stream = std::cout) const = 0;
};

//Tipo de dados lit apenas com a funcionalidade print()
template<typename T = Exp> //O template default é a classe Exp, mas pode-se usar qualquer uma
class Lit : public T {
public:
	int value;

	Lit(int v) : value{v} {};
	
	virtual void print(std::ostream &stream = std::cout) const override {
		stream << value;
	}
};

//classe de teste
class TestLit {
public:
	Lit<> ltree;
	TestLit() : ltree{3} {} 

	void run() {
		ltree.print();
		std::cout << std::endl;
	}
};

#endif
