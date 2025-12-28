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

  template <typename U>
  friend ostream& operator<<(ostream&, const CPoint<U>&);
};

template <typename T>
void CPoint<T>::move(T x, T y) {
  this->x += x;
  this->y += y;
}

template <typename T>
ostream& operator<<(ostream& os, const CPoint<T>& a) {
  os << "(" << a.x << ", " << a.y << ")" << endl;
  return os;
}//스트림 이해완료


int main() {
  CPoint<int> P1(1, 2);
  CPoint<double> P2(1.1, 2.2);

  P1.move(8, 13);
  P2.move(8.97, 20.39);

  cout << P1 << P2;

  return 0;
}