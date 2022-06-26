#ifndef CAT_H
#define CAT_H
#include "pet.h"
class Cat : public Pet{
public:
    Cat(std::string name, double weight){
        if (weight < 2 || weight > 6){
            throw std::range_error("wrong");
        }
        _weight = weight;
        _name = name;
    }
    void feed() override{
        if (_weight + 0.2 > 6){
            throw std::out_of_range("wrong");
        }
        _weight += 0.2;
    }
    ~Cat() {}
};
#endif