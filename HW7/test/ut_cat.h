#include <gtest/gtest.h>

#include "../src/cat.h"

TEST(Cat, Cat_Name){
    Cat c1("Bob", 5);
    ASSERT_EQ("Bob", c1.name());
}

TEST(Cat, Cat_Weight){
    Cat c2("Pet", 2);
    ASSERT_NEAR(2.0, c2.weight(), 0.001);
}

TEST(Cat, Cat_Weight_Error){
    ASSERT_THROW(Cat c3("catcat", 87.0), std::range_error);
}

TEST(Cat, Cat_Feed){
    Cat c4("God", 3.2);
    c4.feed();
    ASSERT_NEAR(3.4, c4.weight(), 0.001);
}

TEST(Cat, Cat_Feed_Error){
    Cat c5("cc", 5.9);
    ASSERT_THROW(c5.feed();, std::out_of_range);
}