#include "../src/cat.h"
#include "../src/toy.h"
#include <gtest/gtest.h>

#include <string>

// add your test here
TEST(cat, add1) {
    ASSERT_THROW(Cat c("",45),std::string);
}
TEST(cat, add2) {
    ASSERT_THROW(Cat c("Sam",51),std::string);
}
TEST(cat, add3) {
    Cat c1("john",15);
    Cat c2("jim",23);
    c2 = c1;
    EXPECT_EQ(c2.getName(),"john");
    EXPECT_EQ(c2.getWeight(),15);
}
TEST(cat, add4) {
    Cat c1("ymz",48);
    Cat c2("haha",32);
    c2 = c1;
    EXPECT_EQ(c2.getName(),"ymz");
    EXPECT_EQ(c2.getWeight(),48);
}
TEST(cat, add5) {
    Cat c1("yuchun",12.3);
    Toy t1("ymz");
    Toy t2("comb");
    c1.addNewToy(t1);
    c1.addNewToy(t2);
    EXPECT_EQ(c1.getToy(0).getName(),"ymz");
}
TEST(cat, add6) {
    Cat c1("jim",25.2);
    Toy t1("bone");
    Toy t2("computer");
    c1.addNewToy(t1);
    c1.addNewToy(t2);
    EXPECT_EQ(c1.getToy(1).getName(),"computer");
}
TEST(cat, add7) {
    Cat c1("jason",39.5);
    Cat c2("jim",25.2);
    EXPECT_EQ(c1.isHeavierThan(c2),true);
}