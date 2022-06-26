#include <string>

class Cat {
public:

  Cat(std::string name, double weight) {
    this->_name = name;
    this->_weight = weight;
    this->_toyCollections = NULL;
    this->_toyAmount = 0;
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

  void addNewToy(std::string toyName) {
    _toyAmount++;
    std::string * newtoy = new std::string[_toyAmount];
    for (int i=0;i<_toyAmount-1;i++){
      newtoy[i] = _toyCollections[i];
    }
    newtoy[_toyAmount-1] = toyName;
    delete[] _toyCollections;
    this->_toyCollections = newtoy;
  }

  std::string getToy(int index) {
    return _toyCollections[index];
  }
  

private:
  std::string _name;
  double _weight;
  std::string * _toyCollections;
  int _toyAmount;

};
