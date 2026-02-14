#include <iostream>
#include "ArrayBag.h"

int main (int argc, char* argv []) {
    int T;
    std :: cin>>T;//파일에서 첫 줄 사용
    
    for (int t = 0; t < T; ++t) {
        int N, M;
        std::cin>>N>>M;//스트림에서 연속 읽기
        ArrayBag <int> A(N);
        ArrayBag <int> B(M);
        for (int i = 0; i < N; ++i) {
                int element;
                std::cin>>element;
                A.add(element);
            }
        for (int i = 0; i < M; ++i) {
            int element;
            std::cin>>element;
            B.add(element) ;
        }


        std::cout<<union_bags(A, B)<<std::endl;//합
        std::cout<<intersect_bags(A, B)<<std::endl ;//교
        std::cout<<A.difference(B)<<std::endl ;//차
        std::cout<<B.difference(A)<<std::endl ;//차
    }
    return 0;
}