/* Google test library needs to be installed in your operational system
   https://github.com/google/googletest/
*/
#include <gtest/gtest.h>
// Includes all test modules
#include "lp_test.cpp"
#include "le_test.cpp"
#include "ap_test.cpp"
#include "ae_test.cpp"
#include "np_test.cpp"
#include "more_tests.cpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
