#include <iostream>

//Interface Exp
class Exp {
public:
	virtual void print() const = 0;
	virtual int eval() const = 0;
};

class Literal : public Exp {
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

class Neg : public Exp {
public:	
	Exp *expr;
	
	Neg(Exp &e) : expr {&e} {}

	virtual void print() const override {
		std::cout << "-(";
		expr->print();
		std::cout << ")";
	}

	virtual int eval() const override {
		return expr->eval() * -1;
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

	Neg menosx {x};
	menosx.print();
	std::cout << '\n' << menosx.eval() << std::endl;

	return 0;
}
