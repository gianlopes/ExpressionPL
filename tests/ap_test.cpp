#include <iostream>
#include <gtest/gtest.h>

#include "../src/ap.cpp"

// Tests for add print module

// Fixture class to be used in tests
class apTest : public testing::Test {
protected:

    // Declaring literals
    Lit<Exp> a, b, c;

    // Declaring add expression
    Add<Exp> soma, soma2;
    
    // String to redirect print() output
    std::stringstream stream;

    // Constructor
    apTest() : a{5}, b{2}, c{-1}, soma{a,b}, soma2{b,a} {}
};

// Testing print method
TEST_F(apTest, print)
{
    stream.str(""); // Cleaning stream
    a.print(stream);
    EXPECT_EQ(stream.str(),"5");

    stream.str("");
    b.print(stream);
    EXPECT_EQ(stream.str(),"2");

    stream.str("");
    soma.print(stream);
    EXPECT_EQ(stream.str(),"5+2");
}

// Testing print method for sum with negative value literal
TEST_F(apTest, print_with_minus)
{
    stream.str("");
    c.print(stream);
    EXPECT_EQ(stream.str(),"-1");

    Add<Exp> soma3 {a,c}, soma4{c,a};
    stream.str("");
    soma3.print(stream);
    EXPECT_EQ(stream.str(),"5+-1");

    stream.str("");
    soma4.print(stream);
    EXPECT_EQ(stream.str(),"-1+5");
}

// Testing Test class proposed in the article
TEST(apTestMethod, Test)
{
    TestAdd<TestLit> t;
    testing::internal::CaptureStdout();
    t.run();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = "3\n3+3\n" ;
    ASSERT_EQ(output, expected);
}
