/*
Seguindo o artigo do Expression PL, na Figura 2, o programa 6 deve possuir
as operações Print e Eval e os tipos de dados Lit e Neg.

compilar com g++ -o programa6 programa6.cpp lp.o le.o np.o ne.o
*/
#include <iostream>
#include "../lp.cpp" //lit - print
#include "../le.cpp" //lit - eval
#include "../np.cpp" //neg - print
#include "../ne.cpp" //neg - eval

int main()
{
    /* Instanciando a classe de testes. */
    TestNegEval<TestLitEval<TestNeg<TestLit>>> teste;
    /* Lembrando que a ordem importa. */
    teste.run();
    return 0;
}
