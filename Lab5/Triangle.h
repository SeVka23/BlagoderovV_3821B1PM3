#pragma once
#include "Obj.h"
#include "Board.h"
template <class T>
class TTriangle : public TObj<T>
{
public:
  TTriangle();
  ~TTriangle();
  virtual void Plot();
  virtual void Print();
  virtual TVector<T>& operator[](int i);
  virtual int GetDim();
  virtual TString& GetName();
  virtual void SetName(const TString& p);
protected:
  TVector<T> Fp, Sp, Tp;
  TString name;
  int dim;
};

template<class T>
inline TTriangle<T>::TTriangle()
{
  std::cout << "Your triangle: " << std::endl;
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
  std::cout << "Enter dim of third point" << std::endl;
  std::cin >> dim;
  TVector<T> temp3(dim, 3);
  Tp = temp3;
  std::cin >> Tp;
  dim = Fp.GetLen();
  if ((Fp.GetLen() != Sp.GetLen()) || (Fp.GetLen() != Tp.GetLen()) || (Sp.GetLen() != Tp.GetLen())) throw "error";
  name = "Triangle";
}

template<class T>
inline TTriangle<T>::~TTriangle()
{
}

template<class T>
inline void TTriangle<T>::Plot()
{
  TBoard<T> temp;
  temp.DrawLine(Fp[0], Fp[1], Sp[0], Sp[1]);
  temp.DrawLine(Sp[0], Sp[1], Tp[0], Tp[1]);
  temp.DrawLine(Tp[0], Tp[1], Fp[0], Fp[1]);
  temp.PrintBoard();
}

template<class T>
inline void TTriangle<T>::Print()
{
  std::cout << name << std::endl;
  std::cout << "First vertex " << Fp << std::endl;
  std::cout << "Second vertex " << Sp << std::endl;
  std::cout << "Third vertex " << Tp << std::endl;
}

template<class T>
inline TVector<T>& TTriangle<T>::operator[](int i)
{
  if (i == 0) return Fp;
  if (i == 1) return Sp;
  if (i == 2) return Tp;
}

template<class T>
inline int TTriangle<T>::GetDim()
{
  return dim;
}

template<class T>
inline TString& TTriangle<T>::GetName()
{
  return name;
}

template<class T>
inline void TTriangle<T>::SetName(const TString& p)
{
  name = p;
}