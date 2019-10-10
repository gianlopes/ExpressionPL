/*

Program6 is an example of the 8 possible compositions possible listed
in the ExpressionPL article figure 2. 
It only has access to Lit and Neg with print and eval functionality

To run from ExpressionPL directory do:
    make
    ./src/programs/program6

*/
#include <iostream>
#include "../lp.cpp" //lit - print
#include "../le.cpp" //lit - eval
#include "../np.cpp" //neg - print
#include "../ne.cpp" //neg - eval

int main()
{
    // Creating test object
    TestNegEval<TestLitEval<TestNeg<TestLit>>> teste;
    // Note that the order of composition changes results
    teste.run();
    return 0;
}
