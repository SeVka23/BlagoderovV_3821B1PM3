#include <iostream>
#include "Storage.h"
int main()
{
  TPoint<int> A(2);
  TLine<int> l1;
  TCircle<int> C1;
  TTriangle<int> t1;
  TSquare<int> sq1;
  TRectangle<int> rec1;
  TStorage<int> book;
  book.AddShape(&A);
  book.AddShape(&l1);
  book.AddShape(&C1);
  book.AddShape(&t1);
  book.AddShape(&sq1);
  book.AddShape(&rec1);
  book.DelShape(0);
  book.Print();
  book.Plot();
  return 0;
}