#include <iostream>

//Interface Exp
class Exp {
public:
	virtual void print() const = 0;
	virtual int eval() const = 0;
};

class Lit : public Exp {
public:
	int value;

	Lit(int v) : value{v} {};
	
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

class Test {
public:
	Lit ltree;
	Add atree;
	Neg ntree;
	Test() : ltree{3}, atree{ltree, ltree}, ntree{ltree} {} 

	void run() {
		ltree.print();
		std::cout << std::endl;
		atree.print();
		std::cout << std::endl;
		ntree.print();
		std::cout << std::endl;
		std::cout << ltree.eval() << std::endl;
		std::cout << atree.eval() << std::endl;
		std::cout << ntree.eval() << std::endl;
	}
};


int main()
{
	Test test {};
	test.run();

	return 0;
}
