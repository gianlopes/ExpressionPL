/*
This example shows the flexibility of this implementation, where 
we can split module lp (from src) into two different files, separating
the print functionality from the Lit definition and still be able
to use the other modules (le.cpp in this example) without needing
further modifications.

To run from ExpressionPL directory do:
    make
    ./src/programs/example
*/

#include "lit.cpp"
#include "print.cpp"
#include "../../le.cpp"

int main()
{
    // Lit with no methods
    Lit<Exp> a{0};
    
    // Lit with print method
    LitPrint<Lit<ExpPrint<Exp>>> b{10};
    std::cout << "b.print() = ";
    b.print();
    std::cout<< std::endl;

    // A Lit with print and eval
    LitEval<LitPrint<Lit<ExpPrint<ExpEval<Exp>>>>> c{15};
    std::cout << "c.print() = ";
    c.print();
    std::cout<< std::endl << "c.eval() = " << c.eval() << std::endl;

    std::cout << "Test Class1:\n";

    // Combined tests
    TestLitEval<TestLitPrint<TestLit>> t1;
    t1.run();

    std::cout << "Test Class2:\n";

    // Can be done in different order as long as TestLit is the first
    // as it's the module de introduces the test class.
    TestLitPrint<TestLitEval<TestLit>> t2;
    t2.run();

    return 0;
}
