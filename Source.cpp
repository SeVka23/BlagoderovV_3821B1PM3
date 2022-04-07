#include "Build/Complex.h"
#include <iostream>
int main()
{
  TComplex a;
  TComplex b(3, 6);
  TComplex c;
  TComplex d;
  std::cin >> a;
  std::cout << a << std::endl;
  c = a.operator*(b);
  d = b.operator/(a);
  std::cout << a <<"\t"<< b << "\t" << c << "\t" << d <<std::endl;
  return 0;
}