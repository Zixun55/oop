#include <gtest/gtest.h>

#include "../src/dog.h"

TEST(Dog, Dog_Name){
    Dog d1("ymz", 30.0);
    ASSERT_EQ("ymz", d1.name());
}

TEST(Dog, Dog_Weight){
    Dog d2("dog", 40.0);
    ASSERT_NEAR(40.0, d2.weight(), 0.001);
}

TEST(Dog, Dog_Weight_Error){
    ASSERT_THROW(Dog d3("wolf", 87.0);, std::range_error);
}

TEST(Dog, Dog_Feed){
    Dog d4("bird", 30.0);
    d4.feed();
    ASSERT_NEAR(30.8, d4.weight(), 0.001);
}

TEST(Dog, Dog_Feed_Error){
    Dog d5("mouse", 49.3);
    ASSERT_THROW(d5.feed();, std::out_of_range);
}