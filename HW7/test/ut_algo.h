#include <gtest/gtest.h>
#include "../src/algo.h"
#include <vector>
// class AlgoTest : public ::testing::Test{
// protected:

// };
using namespace pet_compare;
TEST(algo, Max){
    Cat *c1 = new Cat("Cat", 5);
    Cat *c2 = new Cat("chicken", 4);
    Cat *c3 = new Cat("circle", 3);
    Dog *d1 = new Dog("Dog", 39);
    Dog *d2 = new Dog("DD", 42);
    Dog *d3 = new Dog("dangerous", 23);
    std::vector<Pet *> pet = {c1, c2, c3, d1, d2, d3};
    ASSERT_EQ(maxPet(pet.begin(), pet.end(), largerWeight)[0]->weight(), 42);
    ASSERT_EQ(maxPet(pet.begin(), pet.end(), longerName)[0]->name(), "dangerous");
    delete c1;
    delete c2;
    delete c3;
    delete d1;
    delete d2;
    delete d3;
}
