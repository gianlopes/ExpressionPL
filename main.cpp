#include <iostream>

//Interface Exp
class Exp {
public:
	virtual void print() const = 0;
	virtual int eval() const = 0;
};

class Literal: public Exp {
public:
	int value;

	Literal(int v) : value{v} {};
	
	virtual void print() const override {
		std::cout << value;
	}

	virtual int eval() const override {
		return value;
	}
};

class Add : public Exp {
public:
	const Exp *left;
	const Exp *right;
	Add(Exp &l, Exp &r) : left{&l}, right{&r} {}

	virtual void print() const override {
		left->print();
		std::cout << '+';
		right->print();
	}

	virtual int eval() const override {
		return left->eval() + right->eval();
	}

};

int main()
{
	Literal x {11};
	x.print();
	std::cout << '\n'<< "Valor de x = " << x.eval() << std::endl;
	Literal y {5};
	y.print();
	std::cout << '\n' << "Valor de y = " << y.eval() << std::endl;
	
	Add soma {x,y};
	soma.print();
	std::cout << " = " << soma.eval() << std::endl;

	return 0;
}
