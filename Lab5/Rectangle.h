#pragma once
#include "Obj.h"
template <class T>
class TRectangle : public TObj<T>
{
public:
  TRectangle();
  ~TRectangle();
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
inline TRectangle<T>::TRectangle()
{
  std::cout << "Your rectangle: " << std::endl;
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
  name = "Rectangle";
}

template<class T>
inline TRectangle<T>::~TRectangle()
{
}

template<class T>
inline void TRectangle<T>::Plot()
{
  char list[50][50];
  TVector<T> temp1 = Fp;
  TVector<T> temp2 = Sp;
  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
      list[i][j] = '*';
  list[(int)temp1[0]][(int)temp1[1]] = '.';
  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
    {
      if ((list[i][j] == '.') && (j < (int)temp2[0]))
        list[i][j + 1] = '.';
      if ((list[i][j] == '.') && (j == (int)temp2[0]) && (i < (int)temp2[1]))
        list[i + 1][j] = '.';
    }
  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
    {
      if ((list[i][j] == '.') && (j == (int)temp1[0]) && (i < (int)temp2[1]))
        list[i + 1][j] = '.';
      if ((list[i][j] == '.') && (i == (int)temp2[1]) && (j < (int)temp2[0]))
        list[i][j + 1] = '.';
    }
  for (int i = 0; i < 50; i++)
  {
    std::cout << std::endl;
    for (int j = 0; j < 50; j++)
      std::cout << list[i][j];
  }
}

template<class T>
inline void TRectangle<T>::Print()
{
  std::cout << name << std::endl;
  std::cout << "First vertex " << Fp << std::endl;
  std::cout << "Second vertex " << Sp << std::endl;
}

template<class T>
inline TVector<T>& TRectangle<T>::operator[](int i)
{
  if (i == 0) return Fp;
  if (i == 1) return Sp;
}

template<class T>
inline int TRectangle<T>::GetDim()
{
  return dim;
}

template<class T>
inline TString& TRectangle<T>::GetName()
{
  return name;
}

template<class T>
inline void TRectangle<T>::SetName(const TString& p)
{
  name = p;
}
