#include <iostream>
#include "lp.cpp"
#include "le.cpp"
#include "ap.cpp"
#include "ae.cpp"
#include "np.cpp"
#include "ne.cpp"

int main()
{
    std::cout << std::endl << "Lit + Print" << std::endl;

    Lit<> t1 {3};
    t1.print();

    std::cout << std::endl << "CLASSE TESTE1:" << std::endl;
    Test test;
    test.run();


    std::cout << std::endl << "Lit + Print + Eval:" << std::endl;
    //LitE é um Lit com a funcionalidade eval()
    LitE t2 {5};
    std::cout << "t2 = " << t2.eval();
    t2.print();

    std::cout << std::endl << "CLASSE TESTE2:" << std::endl;
    TestLitEval<Test> test2;
    test2.run();


    std::cout << std::endl << "Lit + Add + Print:" << std::endl;
    Lit<> a {5};
    Lit<> b {7};
    Add<> soma {a,b};
    soma.print();

    std::cout << std::endl << "CLASSE TESTE3:" << std::endl;
    TestAdd<Test> test3;
    test3.run();


    std::cout << std::endl << "Lit + Add + Print + Eval:" << std::endl;
    LitE c {10};
    LitE d {9};

    AddEval<Add<ExpEval<Exp>>> soma2 {c, d};
    soma2.print();
    std::cout << " = " << soma2.eval();

    std::cout << std::endl << "CLASSE TESTE4:" << std::endl;
    TestAddEval <TestLitEval<TestAdd<Test>>> test4;
    test4.run();


    std::cout << std::endl << "Lit + Neg + Print:" << std::endl;
    Neg<> menos_a {a};
    menos_a.print();

    std::cout << std::endl << "CLASSE TESTE5:" << std::endl;
    TestNeg<Test> test5;
    test5.run();


    std::cout << std::endl << "Lit + Neg + Print + Eval:" << std::endl;
    NegEval<Neg<ExpEval<Exp>>> menos_c {c};
    menos_c.print();
    std::cout << " = " << menos_c.eval();

    std::cout << std::endl << "CLASSE TESTE6:" << std::endl;
    TestNegEval<TestLitEval<TestNeg<Test>>> test6;
    test6.run();


    std::cout << std::endl << "Lit + Add + Neg + Print:" << std::endl;
    Add<> b_menos_a {b,menos_a};
    b_menos_a.print();

    std::cout << std::endl << "CLASSE TESTE7:" << std::endl;
    TestNeg<TestAdd<Test>> test7;
    test7.run();


    std::cout << std::endl << "Lit + Add + Neg + Print + Eval:" << std::endl;
    AddE d_menos_c {d,menos_c};
    d_menos_c.print();
    std::cout << " = " << d_menos_c.eval();
    std::cout << std::endl << "CLASSE TESTE8:" << std::endl;
    TestNegEval<TestAddEval<TestLitEval<TestNeg<TestAdd<Test>>>>> test8;
    test8.run();

    return 0;
}
