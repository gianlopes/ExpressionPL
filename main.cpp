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
		std::cout << value << std::endl;
	}

	virtual int eval() const override {
		return value;
	}
};

int main()
{
	Literal x {10};
	x.print();
	std::cout << "Valor de x = " << x.eval();
	return 0;
}