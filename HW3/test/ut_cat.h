#include "../src/cat.h"

#include <gtest/gtest.h>

// add your test here
TEST(Vector, add1) {
    Cat c1("Sam",12.5);
    c1.addNewToy("mouse");
    c1.addNewToy("bone");
    EXPECT_EQ(c1.getToy(1),"bone");
}
TEST(Vector, add2) {
    Cat c1("jim",21.4);
    c1.addNewToy("hat");
    c1.addNewToy("ball");
    EXPECT_EQ(c1.getToy(1),"ball");
}
TEST(Vector, add3) {
    Cat c1("jason",52.2);
    c1.addNewToy("ymz");
    c1.addNewToy("comb");
    EXPECT_EQ(c1.getToy(0),"ymz");
}
TEST(Vector, add4) {
    Cat c1("jimmy",1.21);
    c1.addNewToy("computer");
    c1.addNewToy("cellphone");
    EXPECT_EQ(c1.getToy(0),"computer");
}
TEST(Vector, add5) {
    Cat c1("michael",3.21);
    EXPECT_EQ(c1.getName(),"michael");
}
TEST(Vector, add6) {
    Cat c1("jay",2.65);
    EXPECT_EQ(c1.getName(),"jay");
}
TEST(Vector, add7) {
    Cat c1("simon",9.8);
    EXPECT_EQ(c1.getWeight(),9.8);
}
TEST(Vector, add8) {
    Cat c1("happy",4.6);
    EXPECT_EQ(c1.getWeight(),4.6);
}
