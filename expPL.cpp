#include <iostream>
#include "lp.cpp"
#include "le.cpp"
#include "ap.cpp"
#include "ae.cpp"

int main()
{
    std::cout << std::endl << "Lit + Print" << std::endl;

    Lit<> t1 {3};
    t1.print();

    std::cout << std::endl << "CLASSE TESTE:" << std::endl;
    Test test;
    test.run();


    std::cout << std::endl << "Lit + Print + Eval:" << std::endl;


    //LitE é um Lit com a funcionalidade eval()
    LitE t2 {5};
    std::cout << "t2 = " << t2.eval() << std::endl;
    t2.print();

    std::cout << std::endl << "CLASSE TESTE:" << std::endl;
    TestLitEval <Test> test2;
    test2.run();


    std::cout << std::endl << "Lit + Add + Print:" << std::endl;
    Lit<> a {5};
    Lit<> b {7};
    Add<> soma {a,b};
    soma.print();

    std::cout << std::endl << "CLASSE TESTE:" << std::endl;
    TestAdd <Test> test3;
    test3.run();

    std::cout << std::endl << "Lit + Add + Print + Eval:" << std::endl;
    LitE c {10};
    LitE d {9};

    AddEval<Add<ExpEval<Exp>>> soma2 {c, d};
    soma2.print();
    std::cout << " = " << soma2.eval() << std::endl;

    std::cout << std::endl << "CLASSE TESTE:" << std::endl;
    TestAddEval <TestLitEval<TestAdd<Test>>> test4;
    test4.run();

    return 0;
}
