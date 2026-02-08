#include <iostream>
using namespace std;

template <class T>
class CPoint{
    private:
        T coox;
        T cooy;
    public:
        CPoint(T x, T y){
            coox = x;
            cooy = y;
        };

        void move(T x, T y);
        ostream operator<<(CPoint U);

        //아래꺼 <<를 오버로딩하면 좌측이 ostream이니까 멤버변수로 넣을수가 없음. 따라서 friend선언해서 <<연산자 오버로딩.
        friend ostream& operator<<(ostream& os, const CPoint<T>& p){//ostream은 무조건 붙여라 레퍼런스변수로 다뤄라.

           os << "(" << p.coox << ", " << p.cooy << ")" << endl;//반환형에 신경쓸것
           return os;

        }
 
};


template <class T>
void CPoint<T>::move(T x, T y){
    this->coox += x;
    this->cooy += y;

}


int main() {

    CPoint<int> P1(1, 2);
    CPoint<double> P2(1.1, 2.2);
    P1.move(8, 13);
    P2.move(8.97, 20.39);
    cout << P1 << P2;
    return 0;

}