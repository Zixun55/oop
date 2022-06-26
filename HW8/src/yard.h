#ifndef YARD_H
#define YARD_H

#include <vector>

#include "pet.h"

class Yard
{
public:
    Yard() = default;
    Yard(const std::vector<Pet *> &v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i]->kind() == "DOG")
            {
                _pets.push_back(new Dog(v[i]->name(), v[i]->weight()));
            }
            else
            {
                _pets.push_back(new Cat(v[i]->name(), v[i]->weight()));
            }
        }
    }

    Yard &operator=(const Yard &other)
    {
        if (this != &other)
        {
            for (int i = 0; i < other._pets.size(); i++)
            {
                if (other._pets[i]->kind() == "DOG")
                {
                    _pets.push_back(new Dog(other._pets[i]->name(), other._pets[i]->weight()));
                }
                else
                {
                    _pets.push_back(new Cat(other._pets[i]->name(), other._pets[i]->weight()));
                }
            }
        }
        return *this;
    }
    Yard(const Yard &other)
    {
        if (this != &other)
        {
            for (int i = 0; i < other._pets.size(); i++)
            {
                if (other._pets[i]->kind() == "DOG")
                {
                    _pets.push_back(new Dog(other._pets[i]->name(), other._pets[i]->weight()));
                }
                else
                {
                    _pets.push_back(new Cat(other._pets[i]->name(), other._pets[i]->weight()));
                }
            }
        }
    }
    ~Yard()
    {
        for (int i = 0; i < _pets.size(); i++)
        {
            delete _pets[i];
        }
    }

    template <typename Condition>
    std::vector<Pet *> getPetWithCondition(Condition cond)
    {
        std::vector<Pet *> pets_in_cond;
        for (Pet *pet : _pets)
        {
            if (cond(pet))
            {
                pets_in_cond.push_back(pet);
            }
        }
        return pets_in_cond;
    }
    void addPet(Pet * pet){
        _pets.push_back(pet);
    }

private:
    std::vector<Pet *> _pets;
};

#endif /* end of include guard: YARD_H */