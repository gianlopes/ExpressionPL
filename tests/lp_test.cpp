#include <iostream>
#include <gtest/gtest.h>

#include "../src/lp.cpp"

// Tests for lit print module

// Fixture class to be used in tests
class lpTest : public testing::Test {
protected:
    // Declaring literals
    Lit<Exp> a, b;
    // String to redirect print() output
    std::stringstream stream;

    // Constructor
    lpTest() : a{5}, b{-5} {}
};

// Testing positive value assigned in constructor
TEST_F(lpTest, value)
{
    ASSERT_EQ(a.value,5);
}

// Testing negative value assigned in constructor
TEST_F(lpTest, value_with_Minus)
{
    ASSERT_EQ(b.value,-5);
}

// Testing print method
TEST_F(lpTest, print)
{
    a.print(stream);
    EXPECT_EQ(stream.str(),"5");
    EXPECT_NE(stream.str(),"");
}

// Testing print method for negative value
TEST_F(lpTest, print_with_minus)
{
    b.print(stream);
    EXPECT_EQ(stream.str(),"-5");
}

// Testing Test class proposed in the article
TEST(lpTestMethod, Test)
{
    TestLit t;
    testing::internal::CaptureStdout();
    t.run();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = "3\n" ;
    ASSERT_EQ(output, expected);

}
