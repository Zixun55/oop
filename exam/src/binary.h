#ifndef Binary_H
#define Binary_H
#include <string>
#include <math.h>

class Binary{
public:
    Binary(){}
    Binary(int input[],int s){
        this->_s = s;
        
        for (int i = 0;i < s;i++){
            if (input[i] > 1 || input[i] < 0){
                throw std::string("Exception.");
            }
            this->_input[i] = input[i];
        }
        // if (_input[0] == NULL){
        //     throw std::string("Exception.");
        // }
    }
    Binary(const Binary & b){
        this->_s = b._s;
        for (int i = 0;i < this->_s;i++){
            this->_input[i] = b._input[i];
        }
    }
    ~Binary(){ }
    Binary & operator=(Binary const &b){
        _s = b._s;
        for (int i = 0;i < this->_s;i++){
            _input[i] = b._input[i];
        }
        return *this;
    }
    Binary operator+(Binary const &b){
        return *this;
    }
    Binary operator-(Binary const &b){
        return *this;
    }
    Binary operator>>(int a){
        int store_bits[this->_s];
        for (int i=0;i<this->_s;i++){
            store_bits[i] = this->_input[i];
            this->_input[i] = 0;
        }
        for (int i=a;i<this->_s;i++){
            this->_input[i] = store_bits[i-a];
        }
        return *this;
    }
    Binary operator<<(int a){
        int store_bits[this->_s];
        for (int i=0;i<this->_s;i++){
            store_bits[i] = this->_input[i];
            this->_input[i] = 0;
        }
        for (int i=a;i<this->_s;i++){
            this->_input[i-a] = store_bits[i]; 
        }
        return *this;
    }
    void resize(int new_size){
        if(new_size < _s){
            throw std::string("Exception.");
        }
        int new_bits[new_size];
        for (int i=0;i<new_size-this->_s;i++){
            new_bits[i] = 0;
        }
        int j = 0;
        for (int i=new_size-this->_s;i<new_size;i++){
            new_bits[i] = this->_input[j];
            j++;
        }
        for (int i = 0;i<new_size;i++){
            this -> _input[i] = new_bits[i]; 
        }
        this->_s = new_size;
    }
    void setBit(int pos,int a){
        this->_input[pos] = a;
    }
    int toInt() const{
        
        int total = 0;
        for (int i=0;i<this->_s;i++){
            total+=_input[i]*(pow(2,_s-i-1));
        }
        return total;
    }
    std::string toString() const{
        std::string str = "";
        for (int i=0;i<this->_s;i++){
            str += std::to_string(this->_input[i]);
        }
        return str;
    }
    private:
        int  _input[100];
        int _s;
};

#endif
