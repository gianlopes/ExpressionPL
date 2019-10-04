#include <iostream>
#include <gtest/gtest.h>
#include "lp.cpp"

class lpTest : public testing::Test {
protected:
    // Constructor
    lpTest() : a{5} {}

    Lit<Exp> a;
};

TEST_F(lpTest, value)
{
    ASSERT_EQ(a.value,5);
}

TEST_F(lpTest, print)
{
    testing::internal::CaptureStdout();
    a.print();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output,"5");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}