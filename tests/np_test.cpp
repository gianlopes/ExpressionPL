#include <iostream>
#include <gtest/gtest.h>

#include "../src/lp.cpp"
#include "../src/np.cpp"

// Tests for add print module

// Fixture class to be used in tests
class npTest : public testing::Test {
protected:

    // Declaring literals
    Lit<Exp> a, b;

    // Declaring Neg expression
    Neg<Exp> aneg, bneg;
    
    // String to redirect print() output
    std::stringstream stream;

    // Constructor
    npTest() : a{5}, b{-2}, aneg{a}, bneg{b} {}
};

// Testing print method
TEST_F(npTest, print)
{
    a.print(stream);
    EXPECT_EQ(stream.str(),"5");

    stream.str(""); // Cleaning stream
    b.print(stream);
    EXPECT_EQ(stream.str(),"-2");

    stream.str("");
    aneg.print(stream);
    EXPECT_EQ(stream.str(),"-(5)");

    stream.str("");
    bneg.print(stream);
    EXPECT_EQ(stream.str(),"-(-2)");
}

TEST(npTestMethod, Test)
{
    TestNeg<TestLit> t;
    testing::internal::CaptureStdout();
    t.run();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = "3\n-(3)\n" ;
    ASSERT_EQ(output, expected);
}