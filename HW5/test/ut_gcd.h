#include <gtest/gtest.h>
#include "../src/gcd.h"

TEST(gcd, gcd1) {
    int a = gcd(6,2);
    ASSERT_EQ(a,2);
}
TEST(gcd, gcd2) {
    int a = gcd(-18,12);
    ASSERT_EQ(a,6);
}