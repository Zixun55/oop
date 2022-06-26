#include "../src/dot.h"


// A single test case has the following form:
//
TEST(TestSuiteName, TestName) {
    double u[2]={1,2};
    double v[2]={2,4};
    int dim_u=2,dim_v=2;

    double a[2]={3,4};
    double b[2]={5,6};
    int dim_a=2,dim_b=2;
    ASSERT_NEAR(10,dot(u,dim_u,v,dim_v),0.001); 
    ASSERT_NEAR(39,dot(a,dim_a,b,dim_b),0.001);    
}
TEST(TestSuiteName, TestName1) {
    double u[3]={1,2,3};
    double v[3]={2,4,5};
    int dim_u=3,dim_v=3;

    double a[3]={3,4,5};
    double b[3]={5,6,7};
    int dim_a=3,dim_b=3;
    ASSERT_NEAR(25,dot(u,dim_u,v,dim_v),0.001);    
    ASSERT_NEAR(74,dot(a,dim_a,b,dim_b),0.001); 
}
TEST(TestSuiteName, TestName2) {
    double u[3]={1,2,3};
    double v[4]={2,4,5,6};
    int dim_u=3,dim_v=4;

    double a[3]={3,4,5};
    double b[4]={5,6,7,8};
    int dim_a=3,dim_b=4;
    ASSERT_THROW(dot(u,dim_u,v,dim_v),std::string);
    ASSERT_THROW(dot(a,dim_a,b,dim_b),std::string);
}
TEST(TestSuiteName, TestName3) {
    double u[2]={1,2};
    double v[2]={2,4};
    int dim_u=-1,dim_v=-1;

    double a[2]={1,2};
    double b[2]={2,4};
    int dim_a=2,dim_b=-1;
    ASSERT_THROW(dot(u,dim_u,v,dim_v),std::string);
    ASSERT_THROW(dot(a,dim_a,b,dim_b),std::string);
}