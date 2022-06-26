#ifndef PET_H
#define PET_H
#include <string>
class Pet{
protected:
    std::string _name;
    double _weight;

public:
    virtual void feed() = 0;
    virtual double weight() const{
        return _weight;
    }
    virtual std::string name() const{
        return _name;
    }
    ~Pet() {}
};

#endif