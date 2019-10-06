#include <iostream>
#include <sstream>
#include <gtest/gtest.h>
#include "../lp.cpp"

// Fixture class to be used in tests
class lpTest : public testing::Test {
protected:
    // Declaring literal a
    Lit<Exp> a;
    // String to redirect print() output
    std::stringstream stream;

    // Constructor
    lpTest() : a{5} {}

};

// Testing value assigned in constructor
TEST_F(lpTest, value)
{
    ASSERT_EQ(a.value,5);
}

// Testing print method
TEST_F(lpTest, print)
{
    a.print(stream);
    EXPECT_EQ(stream.str(),"5");
    EXPECT_NE(stream.str(),"");
}

TEST(lpTestMethod, Test)
{
    TestLit t;
    testing::internal::CaptureStdout();
    t.run();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = "3\n" ;
    ASSERT_EQ(output, expected);

}
