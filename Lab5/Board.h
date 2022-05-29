#pragma once
template <class T>
class TBoard
{
public:
  TBoard();
  void DrawLine(T x1, T y1, T x2, T y2);
  void DrawCircle(T x1, T y1, int R);
  void PrintBoard();
protected:
  char list[50][50];
};

template<class T>
inline TBoard<T>::TBoard()
{
  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
      list[i][j] = '*';
}

template<class T>
inline void TBoard<T>::DrawLine(T x1, T y1, T x2, T y2) // Bresenham's line algorithm
{
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
}

template<class T>
inline void TBoard<T>::DrawCircle(T x0, T y0, int R) // Bresenham's circle algorithm
{
  int x = 0;
  int y = R;
  int delta = 1 - 2 * R;
  int error = 0;
  while (y >= 0) {
    list[x0 + x][y0 + y] = '.';
    list[x0 + x][y0 - y] = '.';
    list[x0 - x][y0 + y] = '.';
    list[x0 - x][y0 - y] = '.';
    error = 2 * (delta + y) - 1;
    if (delta < 0 && error <= 0) {
      ++x;
      delta += 2 * x + 1;
      continue;
    }
    error = 2 * (delta - x) - 1;
    if (delta > 0 && error > 0) {
      --y;
      delta += 1 - 2 * y;
      continue;
    }
    ++x;
    delta += 2 * (x - y);
    --y;
  }
}

template<class T>
inline void TBoard<T>::PrintBoard()
{
  for (int i = 0; i < 50; i++)
  {
    std::cout << std::endl;
    for (int j = 0; j < 50; j++)
      std::cout << list[i][j];
  }
}
