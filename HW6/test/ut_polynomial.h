#include <gtest/gtest.h>

#include "../src/polynomial.h"

class poly : public ::testing::Test {
protected:
  const double DELTA = 0.001;
  
  std::vector<Term> a={Term(5, 5),Term(6, 6),Term(4, 4),Term(-2, 2)};
  std::vector<Term> b={Term(3, 3),Term(2, 2),Term(-9, 1)};
  std::vector<Term> c={Term(5, 3),Term(3, 2),Term(10, 1)};
  std::vector<Term> d={Term(-5, 3),Term(4, 2),Term(1, 1)};
  std::vector<Term> e={Term(-5, 2),Term(-4, 2),Term(1, 1)};
  void SetUp() override {
      Term sin(2,2);
  }
};

TEST_F(poly, DefaultConstructor){
  Polynomial p(a,6);
  ASSERT_EQ(0, p.term(3).coefficient());
}

TEST_F(poly, Term1){
  Polynomial p(b,3);
  ASSERT_EQ(3, p.term(3).coefficient());
}

TEST_F(poly, add){
  Polynomial p(a,6);
  Polynomial p2(b,3);
  ASSERT_EQ(0, (p+p2).term(2).coefficient());
}

TEST_F(poly, two_same){
  
  ASSERT_THROW(Polynomial p(e,3),std::string);
}

TEST_F(poly, add2){
  Polynomial p(c,4);
  Polynomial p2(d,5);
  ASSERT_EQ(2, (p+p2).degree());
}

TEST_F(poly, mul_single){
  Polynomial p(a,6);
  Term s(2,2);
  ASSERT_EQ(8, (p*s).term(6).coefficient());
}

TEST_F(poly, mul_poly){
  Polynomial p(a,6);
  Polynomial q(b,6);
  ASSERT_EQ(4, (p*q).term(5).coefficient());
}