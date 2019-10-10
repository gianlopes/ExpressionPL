/* 

Program1 is an example of the 8 possible compositions possible listed
in the ExpressionPL article figure 2. 
It only has access to Lit with print functionality

To run from ExpressionPL directory do:
    make
    ./src/programs/program1

*/

#include "../lp.cpp"
#include <iostream>

int main()
{
    TestLit test1;
    test1.run();
    return 0;
}
