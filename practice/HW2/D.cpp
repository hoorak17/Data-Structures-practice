#include <iostream>
using namespace std;


template <class T>
class CPoint{
    private:
        T coox;
        T cooy;

    public:
        CPoint(T x, T y){//생성자에서도 this포인터 사용가능.
            coox = x;//this사용
            this->cooy = y;//근데 this 없어도 됨
        }

        friend ostream& operator<<(ostream& os, const CPoint<T>& U){//둘 다 레퍼런스를 사용해서 받을 것.
            return os<<"("<<U.coox<<","<<U.cooy<<")"<<endl;//값인지 포인터인지 주의할 것.
        }

        CPoint& operator+=(const CPoint& U);//+=도 구현은 하지만 역할을 +와 분리해서 사용한다.
        CPoint operator+(const CPoint& U) const;//+연산은 매개변수를 바꾸지 않는 쪽으로 진행한다. +=와 아에 다른 연산자라고 생각하고 구현할 것.

};

template <class T>
CPoint<T>& CPoint<T>::operator+=(const CPoint& U){//얘는 원본을 수정할거니까 레퍼런스 변수로 다루고 반환까지
    this->coox += U.coox;
    this->cooy += U.cooy;
    return *this;//연속적으로 +=를 체이닝할 경우를 대비해서 자기자신을 반환
}

template <class T>
CPoint<T> CPoint<T>::operator+(const CPoint& U) const{//함수시그니처 마지막 const는 멤버함수를 호출한 *this를 바꾸지 않겠다는 약속.
    CPoint Temp(*this);//이런 양식의 생성자를 만들지는 않았지만, 암묵적으로 객체 넘기면 복사가되게 cpp에서 돌아간다.
    Temp += U;
    return Temp;
    
}


int main() {

    CPoint<int> P1(1, 2);
    CPoint<int> P2(3, 4);

    CPoint<double> P3(1.1, 2.2);
    CPoint<double> P4(3.3, 4.4);

    P1 = P1 + P2;
    P3 = P3 + P4;

    cout << P1 << P3;
    return 0;

}
