#ifndef CAT_H
#define CAT_H
#include <stdexcept>
#include "pet.h"
class Cat : public Pet{
    public:
        Cat(){}
        Cat(std::string name,double weight):Pet("CAT",name,weight){
            if(weight < 2 || weight > 6){
                throw std::range_error("undefined.");
            }
            ++_amount;
        }
        Cat(Cat const &cat) : Pet(cat){
            ++_amount;
        }
        static int amount() {
            return _amount;
        }
        ~Cat(){
            _amount--;
        }
        void feed() override {
            addweight(0.2);
            if(weight() > 6){
                throw std::out_of_range("undefined.");
            }
        }

    private:
        static int _amount;
};
int Cat::_amount = 0;
#endif