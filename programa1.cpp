#include "lp.cpp"
#include <iostream>

int main()
{
    Lit<Exp> a {10};
    a.print();
    std::cout << std::endl;
    
    TestLit test1;
    test1.run();
    return 0;
}