#include <string>
#include "toy.h"

class Cat {
public:

  Cat(std::string name, double weight) {
    this->_name = name;
    this->_weight = weight;
    this->_toyCollections = NULL;
    this->_toyAmount = 0;
    if (_name == ""){
      throw std::string("undefine.");
    }
    if (_weight < 10 || _weight > 50){
      throw std::string("undefine.");
    }
  }

  Cat(Cat const & other) {
    this->_name = other._name;
    this->_weight = other._weight;
    this->_toyAmount = other._toyAmount;
    Toy * toyCollections = new Toy[other._toyAmount];
    for(int i = 0; i < other._toyAmount; i ++){
        toyCollections[i] = Toy(other._toyCollections[i].getName());
    }
    this->_toyCollections = toyCollections;
  }

   Cat & operator = (Cat const & other) {
     _name = other._name;
     _weight = other._weight;
     _toyAmount = other._toyAmount;
     Toy * toyCollections = new Toy[other._toyAmount];
    for(int i = 0; i < other._toyAmount; i ++){
        toyCollections[i] = Toy(other._toyCollections[i].getName());
    }
    this->_toyCollections = toyCollections;
     return *this;
   }

  ~Cat() {
    delete[] _toyCollections;
  }

  std::string getName() {
    return _name;
  }

  double getWeight() {
    return _weight;
  }

  void addNewToy(Toy const & toyName) {
    _toyAmount++;
    Toy * newtoy = new Toy[_toyAmount];
    for (int i=0;i<_toyAmount-1;i++){
      newtoy[i] = _toyCollections[i];
    }
    newtoy[_toyAmount-1] = toyName;
    delete[] _toyCollections;
    this->_toyCollections = newtoy;
  }

  Toy getToy(int index) const {
    if (index >= _toyAmount || index < 0){
      throw std::string("undefined.");
    }
    else{
      return _toyCollections[index];
    }
  }
  
  bool isHeavierThan(Cat const & other) const {
    if (_weight > other._weight){
      return true;
    }
    else{
      return false;
    }
  }

private:
  std::string _name;
  double _weight;
  Toy * _toyCollections;
  int _toyAmount;
};
