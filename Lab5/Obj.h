#pragma once
#include "Vector.h"
#include "String.h"
#include "Complex.h"
template <class T>
class TObj
{
public:
  virtual void Plot() = 0;
  virtual void Print() = 0;
  virtual TVector<T>& operator[](int i) = 0;
  virtual int GetDim() = 0;
  virtual TString& GetName() = 0;
  virtual void SetName(const TString& p) = 0;
};