#include <iostream>

class Exp {
public:
	virtual void print() const = 0;
};

template<typename Base>
class LitEval : public Base {
public:
    virtual int eval() const = 0;
};


class Lit : public Exp {
public:
	int value;

	Lit(int v) : value{v} {};
	
	virtual void print() const override {
		std::cout << value;
	}
};

class Test {
public:
	Lit ltree;
	Test() : ltree{3}{} 

	void run() {
		ltree.print();
		std::cout << std::endl;
	}
};