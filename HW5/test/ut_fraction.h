#include "../src/fraction.h"
#include <gtest/gtest.h>

class FractionTest : public::testing::Test{
    protected:
        Fraction a;
        Fraction b;
        Fraction c;
        Fraction d;
        Fraction e;
        Fraction f;
        void SetUp() override{
            b = Fraction(9);
            c = Fraction(9, 3);
            d = Fraction(-4, 1);
            e = Fraction(-4, 3);
            f = Fraction(5, 2);
        }
};

TEST_F(FractionTest,test1){
    ASSERT_EQ('+', a.sign());
    ASSERT_EQ(0, a.numerator());
    ASSERT_EQ(1, a.denominator());
}

TEST_F(FractionTest,test2){
    ASSERT_EQ('+', b.sign());
}

TEST_F(FractionTest,test3){
    ASSERT_EQ(9, b.numerator());
    ASSERT_EQ(1, b.denominator());
}

TEST_F(FractionTest,test4){
    ASSERT_EQ('+', c.sign());
}

TEST_F(FractionTest,test5){
    ASSERT_EQ("3", c.toString());
}

TEST(fractiontest,test6){
    ASSERT_THROW(Fraction Throw(3, 0), std::string);
}

TEST_F(FractionTest,test7){
    ASSERT_EQ("5/2", f.toString());
}

TEST_F(FractionTest,test8){
    ASSERT_EQ("-4", d.toString());
}

TEST_F(FractionTest,test9){
    ASSERT_EQ("-4/3", e.toString());
}

TEST_F(FractionTest,test10){
    ASSERT_EQ("11/2", (c + f).toString());
}

TEST_F(FractionTest,test11){
    ASSERT_EQ("1/2", (c - f).toString());
}

TEST_F(FractionTest,test12){
    ASSERT_EQ("-8/15", (e / f).toString());
}