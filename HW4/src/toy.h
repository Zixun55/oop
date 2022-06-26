#include <string>
#ifndef toy_H
#define toy_H


class Toy {
public:

  // constructor with parameter
  Toy(std::string name) {
    this->_name = name;
  }
  Toy(){}
  // get the name of the toy
  std::string getName() const {
    return _name;
  }

private:
  std::string _name;
  
};
#endif