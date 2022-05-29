#pragma once
#include "Obj.h"
#include "Point.h"
template <class T>
class TLine : public TObj<T>
{
public:
  TLine();
  ~TLine();
  virtual void Plot();
  virtual void Print();
  virtual TVector<T>& operator[](int i);
  virtual int GetDim();
  virtual TString& GetName();
  virtual void SetName(const TString& p);
protected:
  TVector<T> Fp, Sp;
  TString name;
  int dim;
};

template<class T>
inline TLine<T>::TLine()
{
  std::cout << "Your line: " << std::endl;
  std::cout << "Enter dim of first point" << std::endl;
  std::cin >> dim;
  TVector<T> temp1(dim, 3);
  Fp = temp1;
  std::cin >> Fp;
  std::cout << std::endl;
  std::cout << "Enter dim of second point" << std::endl;
  std::cin >> dim;
  TVector<T> temp2(dim, 3);
  Sp = temp2;
  std::cin >> Sp;
  dim = Fp.GetLen();
  if (Fp.GetLen() != Sp.GetLen()) throw "error";
  name = "Line";
}

template<class T>
inline TLine<T>::~TLine()
{
}

template<class T>
inline void TLine<T>::Plot()
{
  char list[50][50];
  TVector<T> temp1 = Fp;
  TVector<T> temp2 = Sp;
  int x1 = (int)temp1[0];
  int x2 = (int)temp2[0];
  int y1 = (int)temp1[1];
  int y2 = (int)temp2[1];
  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
      list[i][j] = '*';
  const int deltaX = (int)abs(x2 - x1);
  const int deltaY = (int)abs(y2 - y1);
  const int signX = x1 < x2 ? 1 : -1;
  const int signY = y1 < y2 ? 1 : -1;
  int error = deltaX - deltaY;
  list[x2][y2] = '.';
  while (x1 != x2 || y1 != y2)
  {
    list[x1][y1] = '.';
    int error2 = error * 2;
    if (error2 > -deltaY)
    {
      error -= deltaY;
      x1 += signX;
    }
    if (error2 < deltaX)
    {
      error += deltaX;
      y1 += signY;
    }
  }
  for (int i = 0; i < 50; i++)
  {
    std::cout << std::endl;
    for (int j = 0; j < 50; j++)
      std::cout << list[i][j];
  }
}

template<class T>
inline void TLine<T>::Print()
{
  std::cout << name << std::endl;
  std::cout << "First point " << Fp << std::endl;
  std::cout << "Second point " << Sp << std::endl;
}

template<class T>
inline TVector<T>& TLine<T>::operator[](int i)
{
  if (i == 0) return Fp;
  if (i == 1) return Sp;
}

template<class T>
inline int TLine<T>::GetDim()
{
  return dim;
}

template<class T>
inline TString& TLine<T>::GetName()
{
  return name;
}

template<class T>
inline void TLine<T>::SetName(const TString& p)
{
  name = p;
}
