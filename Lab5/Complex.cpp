#include "Complex.h"
TComplex::TComplex()
{
  re = 0;
  im = 0;
}

TComplex::TComplex(double re_, double im_)
{
  re = re_;
  im = im_;
}

TComplex::TComplex(const TComplex& c)
{
  re = c.re;
  im = c.im;
}

double TComplex::GetRe()
{
  return re;
}

void TComplex::SetRe(double re_)
{
  re = re_;
}

double TComplex::GetIm()
{
  return im;
}

void TComplex::SetIm(double im_)
{
  im = im_;
}

TComplex TComplex::operator+(TComplex& p)
{
  TComplex res;
  res.re += p.re;
  res.im += p.im;
  return res;
}

TComplex TComplex::operator-(TComplex& p)
{
  TComplex res;
  res.re -= p.re;
  res.im -= p.im;
  return res;
}

TComplex TComplex::operator*(TComplex& p)
{
  TComplex res;
  res.re = re * p.re - im * p.im;
  res.im = re * p.im + im * p.re;
  return res;
}

TComplex TComplex::operator/(TComplex& p)
{
  TComplex res;
  if ((p.re == 0) && (p.im == 0))
    throw "Delenie na 0";
  else
  res.re = (re * p.re + im * p.im)/(p.re * p.re + p.im * p.im);
  res.im = (im * p.re - re * p.im)/(p.re * p.re + p.im * p.im);
  return res;
}

TComplex& TComplex::operator=(const TComplex& p)
{
   this->re = p.re;
   this->im = p.im;
  return *this;
}

bool TComplex::operator==(TComplex& p)
{
  if ((p.re == re) && (p.im == im))
    return true;
  else
    return false;
}

std::ostream& operator<<(std::ostream& ostr, TComplex& p)
{
  ostr << p.GetRe() << " + i * " << p.GetIm();
  return ostr;
}

std::istream& operator>>(std::istream& istr, TComplex& p)
{
  std::cout << "Re = " << std::endl;
  istr >> p.re;
  std::cout << "Im = " << std::endl;
  istr >> p.im;
  return istr;
}