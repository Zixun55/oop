#ifndef DOG_H
#define DOG_H
#include <stdexcept>
#include "pet.h"
class Dog : public Pet {
    public:
        Dog(){}
        Dog(std::string name,double weight):Pet("DOG",name,weight){
            if(weight < 10 || weight > 50){
                throw std::range_error("undefined.");
            }
            ++_amount;
        }
        Dog(Dog const &dog) : Pet(dog){
            ++_amount;
        }
        ~Dog() {
            _amount--;
        }
        static int amount() {
            return _amount;
        }

        void feed() override {
            addweight(0.8);
            if(weight() > 50){
                throw std::out_of_range("undefined.");
            }
        }
    private:
        static int _amount;
};
int Dog::_amount = 0;
#endif


