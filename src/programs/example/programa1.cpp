/*
This example shows the flexibility of this implementation, where 
we can split module lp (from src) into two different files, separating
the print functionality from the Lit definition and still be able
to use the other modules (le.cpp in this example) without needing
further modifications.

compile with:
    g++ -std=c++17 programa1.cpp 
run with
    ./a.out
*/

#include "lit.cpp"
#include "print.cpp"
#include "le.cpp"

int main()
{
    // a Lit with no methods
    Lit<Exp> a{0};
    
    // a Lit with print method
    LitPrint<Lit<ExpPrint<Exp>>> b{10};
    b.print();
    std::cout<< std::endl;

    // a Lit with print and eval
    LitEval<LitPrint<Lit<ExpPrint<ExpEval<Exp>>>>> c{15};
    c.print();
    std::cout<< std::endl << c.eval() << std::endl;

    // combined tests
    TestLitEval<TestLitPrint<TestLit>> t2;
    t2.run();

    // can be done in different order as long as TestLit is the first
    // as it's the module de introduces the test class.
    TestLitPrint<TestLitEval<TestLit>> t3;
    t3.run();

    return 0;
}