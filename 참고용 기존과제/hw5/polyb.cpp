#include "polyb.h"
#include <iostream>
using namespace std;

istream& operator>>(istream& is, Polynomial& p) {
 // #terms and (coefficoent, exponent)의 pair 들을 읽어들인다.
 // 높은차수의 항부터 저장되었다고 가정한다.
    int noofterms;
    float coef;
    int exp;
    is >> noofterms;
    for (int i = 0; i < noofterms; i++) {
        is >> coef >> exp; // 계수와 지수 pair 를 읽어들인다.
        p.NewTerm(coef, exp);
        }
    return is;
}
ostream& operator<<(ostream& os, Polynomial& p) {
 // 출력부분
 return os;
}

Polynomial::Polynomial() : capacity(1), terms(0) {
 termArray = new Term[capacity];
}

void Polynomial::NewTerm(const float theCoeff, const int theExp) {
 // 다항식 뒤에 새로운 항을 추가하는 함수
}

Polynomial Polynomial::operator*(Polynomial& b) {
 // 다항식의 곱 작성






 
}