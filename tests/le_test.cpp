#include <iostream>
#include <gtest/gtest.h>

#include "../src/le.cpp"

// Tests for lit eval module

// Fixture class to be used in tests
class leTest : public testing::Test {
protected:
    // Literal with added eval method
    LitEval<Lit<ExpEval<Exp>>> a;
    // LitE is just a more compact way of declaring the above type using typedef
    LitE b, c;
    std::stringstream stream;

    // Constructor
    leTest() : a{5}, b{2}, c{-1} {}

};

// Testing positive value assigned in constructor
TEST_F(leTest, value)
{
    EXPECT_EQ(a.value,5);
    EXPECT_EQ(b.value,2);
}

// Testing negative value assigned in constructor
TEST_F(leTest, value_with_minus)
{
    EXPECT_EQ(c.value,-1);
}

// Testing print method for literals with positive value
TEST_F(leTest, print)
{
    a.print(stream);
    EXPECT_EQ(stream.str(),"5");

    stream.str(""); // Cleaning stream
    b.print(stream);
    EXPECT_EQ(stream.str(),"2");
}

// Testing print method for literals with negative value
TEST_F(leTest, print_with_minus)
{
    c.print(stream);
    EXPECT_EQ(stream.str(),"-1");
}

// Testing eval method
TEST_F(leTest, eval)
{
    EXPECT_EQ(a.eval(),5);
    EXPECT_EQ(b.eval(),2);
}

// Testing eval method for literals with negative value
TEST_F(leTest, eval_with_minus)
{
    EXPECT_EQ(c.eval(),-1);
}

// Testing Test class proposed in the article
TEST(leTestMethod, Test)
{
    TestLitEval<TestLit> t;
    testing::internal::CaptureStdout();
    t.run();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = "3\n3\n" ;
    ASSERT_EQ(output, expected);

}
