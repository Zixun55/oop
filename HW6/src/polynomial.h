#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "term.h"

bool compare(Term a, Term b){
  return (a.exponent() > b.exponent());
}

class Polynomial {
public:
  Polynomial() {}
  Polynomial(std::vector<Term> terms, int degree) {
    std::stable_sort(terms.begin(),terms.end(),compare);

    for (int i = 1;i < terms.size();i++){      //判斷次方是否有重複
      if(terms[i].exponent() == terms[i - 1].exponent()){
        throw std::string("undefined");
      }
    }

    _degree = degree;

    std::vector<int> check;
    for (int i = 0; i < _degree + 1; i++){
      check.push_back(0);
    }
    for (int i = 0; i < terms.size(); i++){
      check[_degree - terms[i].exponent()] = 1;
    }
    for (int i = 0; i < _degree + 1; i++){
      if (check[i] == 0){
        terms.push_back(Term(0.0, _degree - i));
      }
    }
    std::stable_sort(terms.begin(), terms.end(), compare);
    for (int i = 0; i < terms.size(); i++){
      _terms.push_back(terms[i]);
    }
  }

  // get a term by exponent
  // If the term does not exist, return the term (0, exponent)
  Term term(int exponent) const {
    if (exponent > _degree){
      return Term(0,exponent);
    }
    for (int i = 0;i < _terms.size();i++){
      if (exponent == _terms[i].exponent()){
        return _terms[i];
      }
    }
  }

  // get the degree
  int degree() const {
    for (int i = 0;i < _terms.size();i++){
      if (_terms[i].coefficient() != 0){
        return _terms[i].exponent();
      }
    }
  }

  // add two polynomials
  Polynomial operator+ (const Polynomial & q) const {
    int t_degree = this->_degree;
    if (q._degree > this->_degree){
      t_degree = q._degree;
    }

    std::vector<Term> t;
    Polynomial t_this(this->_terms,t_degree);
    Polynomial t_q(q._terms,t_degree);

    for (int i = 0;i < t_this._terms.size();i++){
      t.push_back(t_this._terms[i] + t_q._terms[i]);
    }
    return Polynomial(t,t_degree);
  }

  // multiply by a term
  Polynomial operator* (Term t) const {
    int t_degree = t.exponent() + this->_degree;
    std::vector<Term> temp;
    for (int i = 0;i < this->_terms.size();i++){
      temp.push_back(this->_terms[i] * t);
    }
    return Polynomial(temp,t_degree);
  }

  // multiply by another Polynomial
  Polynomial operator* (const Polynomial & q) const {
    int t_degree = q._degree + this->_degree;
    std::vector<Term> t;
    Term _t;
    for (int i = t_degree;i >= 0;i--){
      t.push_back(Term(0.0,i));
    }

    for (int i = 0;i < this->_terms.size();i++){
      for (int j = 0;j < q._terms.size();j++){
        _t = this->_terms[i] * q._terms[j];
        for (int k = 0;k <= t_degree;k++){
          if (q._terms[j].exponent() + this->_terms[i].exponent() == t[k].exponent()){
            t[k] = t[k] + _t;
          }
        }
      }
    }
    return Polynomial(t,t_degree);
  }

private:
  std::vector<Term> _terms;
  int _degree;
};

#endif
