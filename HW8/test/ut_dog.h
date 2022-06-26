#include "../src/dog.h"
#include "../src/pet.h"

#include <stdexcept>


class DogTest : public ::testing::Test {
protected:
  void SetUp() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  void TearDown() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  const double DELTA = 0.001;
};


TEST_F(DogTest, AmountConstructor) {
  Dog dog("Dog", 30);
  ASSERT_EQ(1, Dog::amount());
}

TEST_F(DogTest, AmountCopyConstructor) {
  Dog dog_1("Dog", 30);
  Dog dog_2 = dog_1;
  ASSERT_EQ(2, Dog::amount());
}

TEST_F(DogTest, AmountPolymorphism) {
  Pet * pet = new Dog("Dog", 30);
  ASSERT_EQ(1, Pet::amount());
  ASSERT_EQ(1, Dog::amount());
  delete pet;
}
TEST_F(DogTest,Exception){
    ASSERT_THROW(Dog dog("John",7),std::range_error);
    ASSERT_THROW(Dog dog("John",67),std::range_error);
    Dog dog("A",49.8);
    dog.feed();
    ASSERT_THROW(dog.feed(),std::out_of_range);    
}
TEST_F(DogTest,feedTest){
    Dog dog("A",23.4);
    dog.feed();    
    dog.feed();
    ASSERT_NEAR(dog.weight(),25,0.01);
}