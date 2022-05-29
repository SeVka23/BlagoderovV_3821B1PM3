#pragma once
#include <iostream>
template <class T>
class TVector
{
public:
  TVector();
  ~TVector();
  TVector(int n, T c);
  TVector(const TVector<T>& p);
  TVector<T> operator + (const TVector<T>& p);
  TVector<T> operator - (const TVector<T>& p);
  TVector<T> operator * (const TVector<T>& p);
  TVector<T> operator / (const TVector<T>& p);
  TVector<T>& operator = (const TVector<T>& p);
  bool operator != (const TVector<T>& p);
  T& operator[](int i);
  int GetLen();
  void Resize(int len_);
  int Count(T c);
  int* AllCount(T c);
protected:
  T* data;
  int len;

};

template<class T>
inline TVector<T>::TVector()
{
  data = 0;
  len = 0;
}

template<class T>
inline TVector<T>::~TVector()
{
  if (data != 0)
  {
    delete[] data;
    data = 0;
  }
  len = 0;
}

template<class T>
inline TVector<T>::TVector(int n, T c)
{
  if (n < 0) throw "n<0";
  data = new T[n];
  len = n;
  for (int i = 0; i < len; i++)
    data[i] = c;
}


template<class T>
inline TVector<T>::TVector(const TVector<T>& p)
{
  len = p.len;
  if (p.len == 0)
    data = 0;
  else
    data = new T[len];
  for (int i = 0; i < len; i++)
    data[i] = p.data[i];
}

template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& p)
{
  TVector<T> res(*this);
  if ((len == p.len) && (p.data != 0) && (data != 0))
  {
    for (int i = 0; i < len; i++)
      res.data[i] = res.data[i] + p.data[i];
  }
  return res;
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& p)
{
  TVector<T> res(*this);
  if ((len == p.len) && (p.data != 0) && (data != 0))
  {
    for (int i = 0; i < len; i++)
      res.data[i] = res.data[i] - p.data[i];
  }
  return res;
}

template<class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& p)
{
  TVector<T> res(*this);
  if ((len == p.len) && (p.data != 0) && (data != 0))
  {
    for (int i = 0; i < len; i++)
      res.data[i] = res.data[i] * p.data[i];
  }
  return res;
}

template<class T>
inline TVector<T> TVector<T>::operator/(const TVector<T>& p)
{
  TVector<T> res(*this);
  if ((len == p.len) && (p.data != 0) && (data != 0))
  {
    for (int i = 0; i < len; i++)
    {
      if (p.data[i] == 0) throw "delenie na 0";
      res.data[i] = res.data[i] / p.data[i];
    }
  }
  return res;
}

template<class T>
inline TVector<T>& TVector<T>::operator=(const TVector<T>& p)
{
  if (this == &p) return *this;
  if (p.data == 0)
  {
    delete[] data;
    data = 0;
    len = 0;
    return *this;
  }
  if (data != 0) delete[] data;
  len = p.len;
  data = new T[len];
  for (int i = 0; i < len; i++)
    data[i] = p.data[i];
  return *this;
}

template<class T>
inline bool TVector<T>::operator!=(const TVector<T>& p)
{
  if (len != p.len) return true;
  else
  {
    for (int i = 0; i < len; i++)
      if (data[i] != p.data[i])
        return true;
  }
  return false;

}

template<class T>
inline T& TVector<T>::operator[](int i)
{
  if (len == 0) throw "not found";
  if ((i < 0) || (i > len)) throw "not found";
  return data[i];
}

template<class T>
inline int TVector<T>::GetLen()
{
  return len;
}

template<class T>
inline void TVector<T>::Resize(int len_)
{
  T* res = 0;
  if (len_ <= 0) throw "no";
  if (len > 0)
  {
    T* res = new T[len_];
    for (int i = 0; i < len_; i++)
      res[i] = data[i];
    if (data != 0)
      delete[] data;
    len = len_;
    data = res;
  }
}

template<class T>
inline int TVector<T>::Count(T c)
{
  int k = 0;
  for (int i = 0; i < len; i++)
    if (data[i] == c) k++;
  return k;
}

template<class T>
inline int* TVector<T>::AllCount(T c)
{
  int count = 0;
  int k = 0;
  for (int i = 0; i < len; i++)
    if (data[i] == c) k++;
  int* q = new int[k];
  for (int j = 0; j < len; j++)
    if (data[j] == c)
    {
      q[count] = j;
      count++;
    }
  return q;
}

template <class T>
std::ostream& operator<<(std::ostream& ostr, TVector<T>& p)
{
  for (int i = 0; i < p.GetLen(); i++)
    ostr << p[i] << " ";
  return ostr;
}

template <class T>
std::istream& operator>>(std::istream& istr, TVector<T>& p)
{
  T a = 0;
  std::cout << "Enter your vector = " << std::endl;
  for (int i = 0; i < p.GetLen(); i++)
  {
    istr >> a;
    p[i] = a;
  }
  return istr;
}
