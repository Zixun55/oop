#ifndef FRC_H
#define FRC_H
#include <string>
#include "gcd.h"

class Fraction {
public:

  // default value is +0/1
  // i.e., _sign='+', _numerator=0, _denominator=1
  Fraction() {
    _denominator = 1;
    _numerator = 0;
    _sign = '+';
  }

  // default value is an integer (denominator=1)
  // e.g., Fraction f(-3) has its _sign='-', _numerator=3, _denominator=1
  Fraction(int num) {
    if(num < 0){
      _sign = '-';
    }
    else{
      _sign = '+';
    }
    _numerator = abs(num);
    _denominator = 1;
  }

  // hint: use gcd
  // throw exception when the denominator is 0
  Fraction(int numerator, int denominator) {
    if (denominator == 0){
      throw std::string("undefined.");
    }
    if((numerator<0 && denominator>0) || (numerator>0 && denominator<0)){
      _sign = '-';
    }
    else{
      _sign = '+';
    }
    int g = gcd(denominator,numerator);
    _denominator = abs(denominator / g);
    _numerator = abs(numerator / g);
  }

  // get the numerator of the fraction
  int numerator() const {
    return _numerator;
  }

  // get the denominator of the fraction
  int denominator() const {
    return _denominator;
  }

  // get positive or negative sign of the fraction
  char sign() const {
    return _sign;
  }

  // display the fraction by string
  std::string toString() const {
    std::string ans;
    if (_sign == '-'){
      ans += _sign;
    }
    ans += std::to_string(_numerator);
    if (_denominator != 1){
      ans += '/';
      ans += std::to_string(_denominator);
    }
    return ans;
  }

  // addition of two Fractions
  Fraction operator + (Fraction const & f) const {
    Fraction ans;
    ans._denominator = _denominator*f._denominator;
    int num1,num2;
    num1 = _numerator * f._denominator;
    num2 = f._numerator * _denominator;
    if(_sign == '-'){
      num1 *= -1;
    }
    if(f._sign == '-'){
      num2 *= -1;
    }
    ans._numerator = num1 +num2;
    if(ans._numerator < 0){
      ans._sign = '-';
    }
    int g = gcd(ans._denominator,ans._numerator);
    ans._denominator /= g;
    ans._numerator /= g;
    ans._numerator = abs(ans._numerator);
    return ans;
  }

  // subtraction of two Fractions
  Fraction operator - (Fraction const & f) const {
    Fraction ans;
    ans._denominator = _denominator*f._denominator;
    int num1,num2;
    num1 = _numerator * f._denominator;
    num2 = f._numerator * _denominator;
    if(_sign == '-'){
      num1 *= -1;
    }
    if(f._sign == '-'){
      num2 *= -1;
    }
    ans._numerator = num1 - num2;
    if(ans._numerator < 0){
      ans._sign = '-';
    }
    int g = gcd(ans._denominator,ans._numerator);
    ans._denominator /= g;
    ans._numerator /= g;
    ans._numerator = abs(ans._numerator);
    return ans;
  }

  // division of two Fractions
  Fraction operator / (Fraction const & f) const {
    Fraction ans;
    ans._denominator = _denominator * f._numerator;
    ans._numerator = _numerator * f._denominator;
    if(_sign == '-'){
      ans._numerator *= -1;
    }
    if(f._sign == '-'){
      ans._numerator *= -1;
    }
    if(ans._numerator < 0){
      ans._sign = '-';
    }
    int g = gcd(ans._denominator,ans._numerator);
    ans._denominator /= g;
    ans._numerator /= g;
    ans._numerator = abs(ans._numerator);
    return ans;
  }

private:
  // both numerator and denominator should be positive
  int _numerator;
  int _denominator;
  char _sign;
};
#endif