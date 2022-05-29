#pragma once
#include "Obj.h"
template <class T>
class TPoint : public TObj<T>
{
public:
  TPoint(int _dim);
  ~TPoint();
  virtual void Plot();
  virtual void Print();
  virtual TVector<T>& operator[] (int i);
  virtual int GetDim();
  virtual TString& GetName();
  virtual void SetName(const TString& p);
protected:
  TVector<T> V;
  TString name;
  int dim;
};

template<class T>
inline TPoint<T>::TPoint(int _dim)
{
  dim = _dim;
  TVector<T> temp(dim, 3);
  V = temp;
  std::cout << "Your point: " << std::endl;
  std::cin >> V;
  name = "Point";
}

template<class T>
inline TPoint<T>::~TPoint()
{
}

template<class T>
inline void TPoint<T>::Plot()
{
  char list[50][50];
  TVector<T> temp = V;
  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
      list[i][j] = '*';
  list[(int)temp[0]][(int)temp[1]] = '.';
  for (int i = 0; i < 50; i++)
  {
    std::cout << std::endl;
    for (int j = 0; j < 50; j++)
      std::cout << list[i][j];
  }
}

template<class T>
inline void TPoint<T>::Print()
{
  std::cout << name << std::endl;
  std::cout << V << std::endl;
}

template<class T>
inline TVector<T>& TPoint<T>::operator[](int i)
{
  return V;
}

template<class T>
inline int TPoint<T>::GetDim()
{
  return dim;
}

template<class T>
inline TString& TPoint<T>::GetName()
{
  return name;
}

template<class T>
inline void TPoint<T>::SetName(const TString& p)
{
  name = p;
}
