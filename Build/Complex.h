#pragma once
#include <iostream>
class TComplex 
{
public:
  TComplex();
  TComplex(double re_, double im_);
  TComplex(const TComplex& c);
  double GetRe();
  void SetRe(double re_);
  double GetIm();
  void SetIm(double im_);
  TComplex operator + (TComplex& p);
  TComplex operator - (TComplex& p);
  TComplex operator * (TComplex& p);
  TComplex operator / (TComplex& p);
  TComplex & operator = (const TComplex& p);
  bool operator == (TComplex& p);
  friend std::ostream& operator<<(std::ostream& ostr, TComplex& p);
  friend std::istream& operator>>(std::istream& istr, TComplex& p);
private: 
  double re;
  double im;
};