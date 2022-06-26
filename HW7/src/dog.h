#ifndef DOG_H
#define DOG_H
#include "pet.h"
class Dog : public Pet{
private:
public:
    Dog(std::string name, double weight){
        if (weight < 10 || weight > 50){
            throw std::range_error("wrong");
        }
        _weight = weight;
        _name = name;
    }
    void feed() override{
        if (_weight + 0.8 > 50){
            throw std::out_of_range("wrong");
        }
        _weight += 0.8;
    }
    ~Dog() {}
};
#endif