//건드리지 않기
# include <iostream>
# include "ArrayBag.h"
using namespace std;

int main (int argc , char * argv []) {
int T;
std :: cin >> T;

for (int t = 0; t < T; ++t) {
//테스트케이스 반복횟수 설정

int N, M;
std :: cin >> N >> M;
//집합의 크기 N,M 설정

ArrayBag <int> A(N) ;//크기N인 arraybagA생성
ArrayBag <int> B(M) ;//크기M인 arraybagB생성

for (int i = 0; i < N; ++i) {
int element ;
std :: cin >> element ;
A.add( element ) ;
}//집합 N 원소채우기

for (int i = 0; i < M; ++i) {
int element ;
std :: cin >> element ;
B.add( element ) ;
}//집합 M 원소채우기



std::cout << union_bags (A, B) << std :: endl ;//합집합출력
std::cout << intersect_bags (A, B) << std :: endl ;//교집합출력
std::cout << A. difference (B) << std :: endl ;//A-B집합출력
std::cout << B. difference (A) << std :: endl ;//B-A집합출력

//테스트케이스 1회 종료
}//테스트케이스 반복 종료

return 0;
}//main 종료
