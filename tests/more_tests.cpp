#include <iostream>
#include <gtest/gtest.h>

#include "../lp.cpp"
#include "../le.cpp"
#include "../ap.cpp"
#include "../ae.cpp"
#include "../np.cpp"
#include "../ne.cpp"

// Tests compositions with different modules

// Fixture class to be used in tests with print method
class lp_ap_np : public testing::Test {
protected:

    Lit<> a, b;
    Neg<> aneg,bneg;

    // String to redirect print() output
    std::stringstream stream;

    // Constructor
    lp_ap_np() : a{5}, b{2}, aneg{a}, bneg{b} {}
};

TEST_F(lp_ap_np, test1)
{
    Add<> soma{bneg,a};

    stream.str("");
    soma.print(stream);
    EXPECT_EQ(stream.str(),"-(2)+5");
}

TEST_F(lp_ap_np, test2)
{
    Add<> soma1{a,b};
    Neg<> nsoma1{soma1};
    Add<> soma2{nsoma1, a};

    stream.str("");
    soma2.print(stream);
    EXPECT_EQ(stream.str(),"-(5+2)+5");
}

// Fixture class to be used in tests where eval and print are enabled
class lp_ap_np_le_ae_ne : public testing::Test {
protected:

    LitEval<Lit<ExpEval<Exp>>> a, b;
    NegEval<Neg<ExpEval<Exp>>> aneg,bneg;

    // String to redirect print() output
    std::stringstream stream;

    // Constructor
    lp_ap_np_le_ae_ne() : a{5}, b{2}, aneg{a}, bneg{b} {}
};

TEST_F(lp_ap_np_le_ae_ne, test1_print)
{
    AddEval<Add<ExpEval<Exp>>> soma{bneg,a};

    stream.str("");
    soma.print(stream);
    EXPECT_EQ(stream.str(),"-(2)+5");
}

TEST_F(lp_ap_np_le_ae_ne, test1_eval)
{
    AddEval<Add<ExpEval<Exp>>> soma{bneg,a};

    
    EXPECT_EQ(soma.eval(),3);
}

TEST_F(lp_ap_np_le_ae_ne, test2_print)
{
    AddEval<Add<ExpEval<Exp>>> soma1{a,b};
    NegEval<Neg<ExpEval<Exp>>> nsoma1{soma1};
    AddEval<Add<ExpEval<Exp>>> soma2{nsoma1, a};

    stream.str("");
    soma2.print(stream);
    EXPECT_EQ(stream.str(),"-(5+2)+5");
}

TEST_F(lp_ap_np_le_ae_ne, test2_eval)
{
    AddEval<Add<ExpEval<Exp>>> soma1{a,b};
    NegEval<Neg<ExpEval<Exp>>> nsoma1{soma1};
    AddEval<Add<ExpEval<Exp>>> soma2{nsoma1, a};

    EXPECT_EQ(soma2.eval(),-2);
}

// Testing Test class combinations proposed in the article
TEST(TestAll, test1)
{
    TestNegEval<TestAddEval<TestLitEval<TestNeg<TestAdd<TestLit>>>>> t;
    testing::internal::CaptureStdout();
    t.run();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = "3\n3+3\n-(3)\n3\n6\n-3\n" ;
    ASSERT_EQ(output, expected);
}

TEST(TestAll, test2)
{
    TestNegEval<TestNeg<TestAddEval<TestAdd<TestLitEval<TestLit>>>>> t;
    testing::internal::CaptureStdout();
    t.run();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = "3\n3\n3+3\n6\n-(3)\n-3\n" ;
    ASSERT_EQ(output, expected);
}
