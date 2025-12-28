#include <iostream>

using namespace std;

template <typename T>
class CPoint {
 private:
  T x;
  T y;

 public:
  CPoint(T a, T b) : x(a), y(b) {}

  void move(T x, T y);

  CPoint<T> operator+(const CPoint<T>&);

  template <typename U>
  friend ostream& operator<<(ostream&, const CPoint<U>&);
};

template <typename T>
CPoint<T> CPoint<T>::operator+(const CPoint<T>& a) {
  return CPoint<T>(this->x + a.x, this->y + a.y);
}

template <typename T>
void CPoint<T>::move(T x, T y) {
  this->x += x;
  this->y += y;
}

template <typename T>
ostream& operator<<(ostream& os, const CPoint<T>& a) {
  os << "(" << a.x << ", " << a.y << ")" << endl;
  return os;
}

int main(void) {
  CPoint<int> P1(1, 2);
  CPoint<int> P2(3, 4);

  CPoint<double> P3(1.1, 2.2);
  CPoint<double> P4(3.3, 4.4);

  P1 = P1 + P2;
  P3 = P3 + P4;

  cout << P1 << P3;

  return 0;
}