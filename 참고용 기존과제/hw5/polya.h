#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
using namespace std;

class Polynomial; // 전방참조
class Term {
    friend class Polynomial;
    friend ostream& operator<<(ostream&, Polynomial&);
    friend istream& operator>>(istream&, Polynomial&);
private:
    float coef; // coefficient
    int exp; // exponent
};
class Polynomial {
public:
    Polynomial(); // construct a polynomial p(x) = 0.
    Polynomial operator+(Polynomial&); // 다항식의 합을 반환
    void NewTerm(const float, const int);
    friend ostream& operator<<(ostream&, Polynomial&);
    friend istream& operator>>(istream&, Polynomial&);
private:
    Term* termArray; //TODO: Array 대신 Linked List 를 사용하는 버전도 구현
    int capacity; // 1 로 초기화
    int terms; // 저장된 항의 수로 0 으로 초기화
};
#endif