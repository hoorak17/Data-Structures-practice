#include <iostream>
using namespace std;

template <class T>
class CPoint{//클래스 선언에는 매개변수 안들어감 추후 생성자에서 처리
    private:
        T coox;
        T cooy;

    public:
        void move(T x, T y);
        void print();

        CPoint(T x, T y){//생성자는 반환형 없음.
            coox = x;
            cooy = y;
        }

};//클래스 끝에는 ;붙인다. 참고, 함수 X 구조체 O

template <class T>
void CPoint<T>::move(T x, T y){//시그니처 박을때 CPoint<T>로 <T>명시할 것.

    this->coox += x;
    this->cooy += y;

}

template <class T>
void CPoint<T>::print(){
    cout<<"("<<this->coox<<", "<<this->cooy<<")"<<endl;

}

int main() {

    CPoint<int> P1(1, 2);
    CPoint<double> P2(1.1, 2.2);

    P1.move(2, 3);
    P2.move(2.2, 3.3);

    P1.print();
    P2.print();
    return 0;

}