#pragma once
#include "Obj.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
template <class T>
class TStorage
{
public:
  TStorage();
  ~TStorage();
  void Print();
  void Plot();
  void Plot(int n);
  void Print(int n);
  void AddShape(TObj<T>* _shape);
  void DelShape(int n);
protected:
  TObj<T>** arr;
  int count;
};

template<class T>
inline TStorage<T>::TStorage()
{
  count = 0;
  arr = 0;
}

template<class T>
inline TStorage<T>::~TStorage()
{
  if (arr != nullptr)
    delete[] arr;
}

template<class T>
inline void TStorage<T>::Print()
{
  for (int i = 0; i < count; i++)
  {
    arr[i]->Print();
  }
}

template<class T>
inline void TStorage<T>::Plot()
{
  for (int i = 0; i < count; i++)
  {
    arr[i]->Plot();
    std::cout << std::endl;
  }
}

template<class T>
inline void TStorage<T>::Plot(int n)
{
  if ((n < 0) && (n > count)) throw "not found";
  else
    arr[n]->Plot();
}

template<class T>
inline void TStorage<T>::Print(int n)
{
  if ((n < 0) && (n > count)) throw "not found";
  else
    arr[n]->Print();
}

template<class T>
inline void TStorage<T>::AddShape(TObj<T>* _shape)
{
  if (count == 0)
  {
    arr = new TObj<T> * [1];
    count = 1;
    arr[0] = _shape;
  }
  else
  {
    TObj<T>** tmp = new TObj<T> * [count + 1];
    for (int i = 0; i < count; i++)
    {
      tmp[i] = arr[i];
    }
    delete[] arr;
    arr = tmp;
    arr[count] = _shape;
    count++;
  }
}

template<class T>
inline void TStorage<T>::DelShape(int n)
{
  if ((n < 0)|| (n>count)) throw "n<0";
  if (arr == 0) throw "error";
  else
    if (arr != 0)
    {
      TObj<T>** tmp = new TObj<T>*[count - 1];
      for (int i = 0; i < count-1; i++)
      {
        if (i == n)
        {
          arr[i] = 0;
          for (int j = i; j < count; j++)
            arr[j] = arr[j + 1];
        }
        tmp[i] = arr[i];
      }
      
      delete[] arr;
      arr = 0;
      count--;
      arr = new TObj<T>*[count];
      for (int j = 0; j < count; j++)
        arr[j] = tmp[j];
    }
}
