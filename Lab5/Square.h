#pragma once
#include "Obj.h"
template <class T>
class TSquare : public TObj<T>
{
public:
  TSquare();
  ~TSquare();
  virtual void Plot();
  virtual void Print();
  virtual TVector<T>& operator[](int i);
  virtual int GetDim();
  virtual TString& GetName();
  virtual void SetName(const TString& p);
  int GetDlina();
protected:
  TVector<T> Fp;
  TString name;
  int dim;
  int dlina;
};

template<class T>
inline TSquare<T>::TSquare()
{
  std::cout << "Your square: " << std::endl;
  std::cout << "Enter dim of first point" << std::endl;
  std::cin >> dim;
  TVector<T> temp1(dim, 3);
  Fp = temp1;
  std::cin >> Fp;
  std::cout << std::endl;
  std::cout << "Enter length of square" << std::endl;
  std::cin >> dlina;
  name = "Square";
}

template<class T>
inline TSquare<T>::~TSquare()
{
}

template<class T>
inline void TSquare<T>::Plot()
{
  char list[50][50];
  TVector<T> temp1 = Fp;
  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
      list[i][j] = '*';
  list[(int)temp1[0]][(int)temp1[1]] = '.';
  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
    {
      if ((list[i][j] == '.') && (j < dlina + (int)temp1[0]))
        list[i][j + 1] = '.';
      if ((list[i][j] == '.') && (j == dlina + (int)temp1[0]) && (i < dlina + (int)temp1[0]))
        list[i + 1][j] = '.';
    }
  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
    {
      if ((list[i][j] == '.') && (j == (int)temp1[0]) && (i < dlina + (int)temp1[0]))
        list[i + 1][j] = '.';
      if ((list[i][j] == '.') && (i == dlina + (int)temp1[0]) && (j < dlina + (int)temp1[0]))
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
inline void TSquare<T>::Print()
{
  std::cout << name << std::endl;
  std::cout << "First vertex " << Fp << std::endl;
  std::cout << "Length square " << dlina << std::endl;
}

template<class T>
inline TVector<T>& TSquare<T>::operator[](int i)
{
  return Fp;
}

template<class T>
inline int TSquare<T>::GetDim()
{
  return dim;
}

template<class T>
inline TString& TSquare<T>::GetName()
{
  return name;
}

template<class T>
inline void TSquare<T>::SetName(const TString& p)
{
  name = p;
}

template<class T>
inline int TSquare<T>::GetDlina()
{
  return dlina;
}
