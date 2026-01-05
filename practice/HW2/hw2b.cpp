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
  void print();
};

template <typename T>
void CPoint<T>::move(T x, T y) {
  this->x += x;
  this->y += y;
}

template <typename T>
void CPoint<T>::print() {
  cout << "(" << x << ", " << y << ")" << endl;
}

int main(void) {
  CPoint<int> P1(1, 2);
  CPoint<double> P2(1.1, 2.2);

  P1.move(2, 3);
  P2.move(2.2, 3.3);

  P1.print();
  P2.print();
  
  return 0;
}