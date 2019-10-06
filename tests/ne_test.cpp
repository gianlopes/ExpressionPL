#include <iostream>
#include <gtest/gtest.h>

#include "../ne.cpp"

// Tests for neg eval module

// Fixture class to be used in tests
class neTest : public testing::Test {
protected:
    // Literal with added eval method
    LitEval<Lit<ExpEval<Exp>>> a, b, c;
    // Add with added eval method
    NegEval<Neg<ExpEval<Exp>>> aneg;
    // NegE is just a more compact way of declaring the above type using typedef
    NegE bneg, cneg;
    // String to redirect print() output
    std::stringstream stream;

    // Constructor
    neTest() : a{8}, b{-12}, c{0}, aneg{a}, bneg{b}, cneg{c} {}
};

// Testing print method for positive value literals
TEST_F(neTest, print)
{
    stream.str(""); // Cleaning stream
    a.print(stream);
    EXPECT_EQ(stream.str(),"8");

    stream.str("");
    aneg.print(stream);
    EXPECT_EQ(stream.str(),"-(8)");
}

// Testing print method for negative value literals
TEST_F(neTest, printMenos)
{
    stream.str("");
    b.print(stream);
    EXPECT_EQ(stream.str(),"-12");

    stream.str("");
    bneg.print(stream);
    EXPECT_EQ(stream.str(),"-(-12)");
}

// Testing print method for literal with value 0
TEST_F(neTest, printZero)
{
    stream.str("");
    c.print(stream);
    EXPECT_EQ(stream.str(),"0");

    stream.str("");
    cneg.print(stream);
    EXPECT_EQ(stream.str(),"-(-0)");
}

// Testing eval method for positive literals
TEST_F(neTest, evalPositivo)
{
    EXPECT_EQ(a.eval(),8);
    EXPECT_EQ(aneg.eval(),-8);
}

// Testing eval method for negative literals
TEST_F(neTest, evalNegativo)
{
    EXPECT_EQ(b.eval(),-12);
    EXPECT_EQ(bneg.eval(),12);
}

// // Testing eval method for zero literal
TEST_F(neTest, evalZero)
{
    EXPECT_EQ(b.eval(),0);
    EXPECT_EQ(bneg.eval(),0);
}

TEST(neTestMethod, Test)
{
    TestNegEval<TestLitEval<TestNeg<TestLit>>> t;
    testing::internal::CaptureStdout();
    t.run();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = "3\n-(3)\n3\n-3\n" ;
    ASSERT_EQ(output, expected);
}
