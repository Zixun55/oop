#include "../src/vector_space.h"

const double DELTA = 0.0001;

// TEST example below.
// Using 'EXPECT' instead of 'ASSERT' here is because if 'ASSERT' fails,
// the delete statement will NOT be executed, which causes memory leak.

TEST(VectorTest, add_test1) {
  double u[3] = {1, 2, 3};
  double v[3] = {4, 5, 6};
	int dim_u = 3;
	int dim_v = 3;
  double * result = add(u, dim_u, v, dim_v);

  EXPECT_NEAR(5, result[0], DELTA);
  EXPECT_NEAR(7, result[1], DELTA);
  EXPECT_NEAR(9, result[2], DELTA);
  delete [] result;   
}
TEST(VectorTest, add_test2) {
  double u[2] = {1.1, 2.2};
  double v[2] = {1, 2};
	int dim_u = 2;
	int dim_v = 2;
  double * result = add(u, dim_u, v, dim_v);

  EXPECT_NEAR(2.1, result[0], DELTA);
  EXPECT_NEAR(4.2, result[1], DELTA);
  delete [] result;   
}
TEST(VectorTest, add_test3) {
  double u[3] = {1, 2, 3};
  double v[2] = {4, 5};
	int dim_u = 3;
	int dim_v = 2;
  ASSERT_THROW(add(u,dim_u,v,dim_v),std::string);
}
TEST(VectorTest, add_test4) {
  double u[3] = {1, 2, 3};
  double v[2] = {4, 5};
	int dim_u = 0;
	int dim_v = 3;
  ASSERT_THROW(add(u,dim_u,v,dim_v),std::string);
}


TEST(VectorTest, scale_test1) {
  double u[3] = {1.1, 2.2, 3.3};
  int dim_u = 3;
	double a = 2;
  double * result = scale(u, dim_u, a);

  EXPECT_NEAR(2.2, result[0], DELTA);
  EXPECT_NEAR(4.4, result[1], DELTA);
  EXPECT_NEAR(6.6, result[2], DELTA);
  delete [] result;  
}
TEST(VectorTest, scale_test2) {
  double u[2] = {5.1,6.2};
	int dim_u = 2;
	double a = 3;
  double * result = scale(u, dim_u, a);

  EXPECT_NEAR(15.3, result[0], DELTA);
  EXPECT_NEAR(18.6, result[1], DELTA);
  delete [] result;  
}
TEST(VectorTest, scale_test3) {
  double u[3] = {7.9, 8.9, 9.9};
	int dim_u = -1;
	int a = 7.2;
  ASSERT_THROW(scale(u,dim_u,a),std::string); 
}