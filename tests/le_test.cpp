#include <iostream>
#include <sstream>
#include <gtest/gtest.h>
#include "../le.cpp"

// Fixture class to be used in tests
class leTest : public testing::Test {
protected:
    // Literal with added eval method
    LitEval<Lit<ExpEval<Exp>>> a;
    // LitE is just a more compact way of declaring this type using typedef
    LitE b;
    // Declaration in different order to test Flexible Order
    LitEval<ExpEval<Lit<Exp>>> c;
    // String to redirect print() output
    std::stringstream stream;

    // Constructor
    leTest() : a{5}, b{10}, c{15} {}

};

// Testing value assigned in constructor
TEST_F(leTest, value)
{
    EXPECT_EQ(a.value,5);
    EXPECT_EQ(b.value,10);
    EXPECT_EQ(c.value,15);
}

// Testing print method
TEST_F(leTest, print)
{
    a.print(stream);
    EXPECT_EQ(stream.str(),"5");

    stream.str(""); // Cleaning stream
    b.print(stream);
    EXPECT_EQ(stream.str(),"10");

    stream.str("");
    c.print(stream);
    EXPECT_EQ(stream.str(),"15");
}

// Testing eval method
TEST_F(leTest, eval)
{
    EXPECT_EQ(a.eval(),5);
    EXPECT_EQ(b.eval(),10);
    EXPECT_EQ(c.eval(),15);
}

TEST(leTestMethod, Test)
{
    TestLitEval<TestLit> t;
    testing::internal::CaptureStdout();
    t.run();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = "3\n3\n" ;
    ASSERT_EQ(output, expected);

}