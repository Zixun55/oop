#include "../src/cat.h"
#include "../src/dog.h"
#include "../src/pet.h"
#include "../src/yard.h"

#include <gtest/gtest.h>
#include <vector>
bool particularweight(Pet* p){
	return p->weight() < 35;
}
struct checkkind {
    bool operator()(Pet* a) const {
        return a->kind() == "DOG";
    }
};
class YardTest : public ::testing::Test {
protected:
  void SetUp() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  void TearDown() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  const double DELTA = 0.001;
};

TEST(YardTest,particularweight_test){
    Pet *dog01 = new Dog("so",11);
    Pet *cat01 = new Cat("soso",5);
    Pet *dog02 = new Dog("sososo",30);
    Pet *cat02 = new Cat("sosososo",3);
    std::vector<Pet*> arr;
    arr.push_back(dog01);
    arr.push_back(cat01);
    arr.push_back(dog02);
    arr.push_back(cat02);
	Yard yard(arr);
	ASSERT_NEAR(yard.getPetWithCondition(particularweight)[0]->weight(),11,0.01);
}
TEST(YardTest,copy_assignment){
	Pet *dog01 = new Dog("so",11);
    Pet *cat01 = new Cat("soso",5);
    Pet *dog02 = new Dog("sososo",30);
    Pet *cat02 = new Cat("sosososo",3);
    std::vector<Pet*> arr;
    arr.push_back(dog01);
    arr.push_back(cat01);
    arr.push_back(dog02);
    arr.push_back(cat02);
	Yard yard(arr);
	Yard y;
	y = yard;
	ASSERT_NEAR(y.getPetWithCondition(particularweight)[0]->weight(),11,0.01);
}
TEST(YardTest,copy_constructor){
	Pet *dog01 = new Dog("so",11);
    Pet *cat01 = new Cat("soso",5);
    Pet *dog02 = new Dog("sososo",30);
    Pet *cat02 = new Cat("sosososo",3);
    std::vector<Pet*> arr;
    arr.push_back(dog01);
    arr.push_back(cat01);
    arr.push_back(dog02);
    arr.push_back(cat02);
	Yard yard(arr);
	Yard y(yard);
	ASSERT_NEAR(y.getPetWithCondition(particularweight)[0]->weight(),11,0.01);
}
TEST(YardTest, lambda){
        std::vector<Pet *> total;
        Pet * p1 = new Dog("Dog1", 30);
        Pet * p2 = new Dog("Dog2", 40);
        Pet * p3 = new Cat("Cat1", 4);
        Pet * p4 = new Cat("Cat2", 3.5);
        total.push_back(p1);
        total.push_back(p2);
        total.push_back(p3);
        total.push_back(p4);
        Yard yard(total);
        ASSERT_NEAR(yard.getPetWithCondition([](Pet * pet) {
            return (pet->weight()<35);
        } )[0]->weight(),30,0.001);
}
TEST(YardTest,functor){
	Pet *dog01 = new Dog("so",11);
    Pet *cat01 = new Cat("soso",5);
    Pet *dog02 = new Dog("sososo",30);
    Pet *cat02 = new Cat("sosososo",3);
    std::vector<Pet*> arr;
    arr.push_back(dog01);
    arr.push_back(cat01);
    arr.push_back(dog02);
    arr.push_back(cat02);
	Yard yard(arr);
	Yard y(yard);
	checkkind ch;
	ASSERT_NEAR(y.getPetWithCondition(ch)[0]->weight(),11,0.01);
}