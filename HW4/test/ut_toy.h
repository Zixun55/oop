#include "../src/toy.h"

#include <gtest/gtest.h>

#include <string>

using std::string;

// add your test here

TEST(Toy, ToyGetName) {
    string name = "mouse";
    Toy toy(name);
    EXPECT_EQ("mouse", toy.getName());
}