#include <iostream>
#include <gtest/gtest.h>

#include "../src/ae.cpp"

// Tests for add eval module

// Fixture class to be used in tests
class aeTest : public testing::Test {
protected:
    // Literal with added eval method
    LitEval<Lit<ExpEval<Exp>>> a, b, c, d, e;
    // Add with added eval method
    AddEval<Add<ExpEval<Exp>>> soma;
    // AddE is just a more compact way of declaring the above type using typedef
    AddE soma2, somaZero, somaMenos;
    // String to redirect print() output
    std::stringstream stream;

    // Constructor
    aeTest() : a{5}, b{2}, c{0}, d{-1}, e{-5}, 
    soma{a,b}, soma2{b,a}, somaZero{c,c}, somaMenos{d,e} {}
};

// Testing print method for positive value literals
TEST_F(aeTest, print)
{
    stream.str("");
    a.print(stream);
    EXPECT_EQ(stream.str(),"5");

    stream.str(""); // Cleaning stream
    b.print(stream);
    EXPECT_EQ(stream.str(),"2");

    stream.str("");
    soma.print(stream);
    EXPECT_EQ(stream.str(),"5+2");
}

// Testing print method for negative value literals
TEST_F(aeTest, printMenos)
{
    stream.str("");
    d.print(stream);
    EXPECT_EQ(stream.str(),"-1");

    stream.str(""); // Cleaning stream
    e.print(stream);
    EXPECT_EQ(stream.str(),"-5");

    stream.str("");
    somaMenos.print(stream);
    EXPECT_EQ(stream.str(),"-1+-5");
}

// Testing print method for zero value literals
TEST_F(aeTest, printZero)
{
    stream.str("");
    c.print(stream);
    EXPECT_EQ(stream.str(),"0");

    stream.str("");
    somaZero.print(stream);
    EXPECT_EQ(stream.str(),"0+0");
}

// Testing eval method for positive value literals
TEST_F(aeTest, eval)
{
    EXPECT_EQ(a.eval(),5);
    EXPECT_EQ(b.eval(),2);
    EXPECT_EQ(soma.eval(),7);
    EXPECT_EQ(soma2.eval(),7);
}

// Testing eval method for negative value literals
TEST_F(aeTest, evalMenos)
{
    EXPECT_EQ(d.eval(),-1);
    EXPECT_EQ(e.eval(),-5);
    EXPECT_EQ(somaMenos.eval(),-6);
}

// Testing eval method for zero value literals
TEST_F(aeTest, evalZero)
{
    EXPECT_EQ(c.eval(),0);
    EXPECT_EQ(somaZero.eval(),0);
}

TEST(aeTestMethod, Test)
{
    TestAddEval<TestLitEval<TestAdd<TestLit>>> t;
    testing::internal::CaptureStdout();
    t.run();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = "3\n3+3\n3\n6\n" ;
    ASSERT_EQ(output, expected);
}
