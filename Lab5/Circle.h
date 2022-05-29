#pragma once
#include "Obj.h"
#include "Board.h"
template <class T>
class TCircle : public TObj<T>
{
public:
  TCircle();
  ~TCircle();
  virtual void Plot();
  virtual void Print();
  virtual TVector<T>& operator[](int i);
  virtual int GetDim();
  virtual TString& GetName();
  virtual void SetName(const TString& p);
  int GetRad();
protected:
  TVector<T> Cp;
  TString name;
  int dim;
  int rad;
};

template<class T>
inline TCircle<T>::TCircle()
{
  std::cout << "Your circle: " << std::endl;
  std::cout << "Enter dim of middle point" << std::endl;
  std::cin >> dim;
  TVector<T> temp1(dim, 3);
  Cp = temp1;
  std::cin >> Cp;
  std::cout << "Enter radius of circle" << std::endl;
  std::cin >> rad;
  name = "Circle";
}

template<class T>
inline TCircle<T>::~TCircle()
{
}

template<class T>
inline void TCircle<T>::Plot()
{
  TBoard<T> temp;
  temp.DrawCircle(Cp[0], Cp[1], rad);
  temp.PrintBoard();
}

template<class T>
inline void TCircle<T>::Print()
{
  std::cout << name << std::endl;
  std::cout << "Middle " << Cp << std::endl;
  std::cout << "Rad " << rad << std::endl;
}

template<class T>
inline TVector<T>& TCircle<T>::operator[](int i)
{
  return Cp;
}

template<class T>
inline int TCircle<T>::GetDim()
{
  return dim;
}

template<class T>
inline TString& TCircle<T>::GetName()
{
  return name;
}

template<class T>
inline void TCircle<T>::SetName(const TString& p)
{
  name = p;
}

template<class T>
inline int TCircle<T>::GetRad()
{
  return rad;
}
