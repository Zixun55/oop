#include "../src/binary.h"

// TEST(Binary_constructor, Sample1){
//   int bits[8]={};
//   ASSERT_THROW(Binary a(bits,8);,std::string);
// }

TEST(Binary_constructor, Sample2){
  int ab[6]={1,-1,1,0,1,0};
  ASSERT_THROW(Binary a(ab,6),std::string);
}

TEST(Binary_right_shift, Sample3){
  int ab[4]={1,1,1,0};
  Binary a(ab, 4);
  ASSERT_THROW(a.resize(3),std::string);
}

TEST(Binary_constructor, Sample4){
  int ab[6]={1,2,1,3,1,0};
  ASSERT_THROW(Binary a(ab,6),std::string);
}
TEST(Binary_constructor, Sample6){
  int ab[6]={0,0,1,0,1,0};
  Binary a(ab,6);
  EXPECT_EQ(a.toInt(),10);
}