#include <iostream>
#include "ArrayBag.h"

int main(int argc, char* argv[]) {
    int T;
    std::cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, M;
        std::cin >> N >> M;

        ArrayBag<int> A(N);
        ArrayBag<int> B(M);

        for (int i = 0; i < N; ++i) {
            int element;
            std::cin >> element;
            A.add(element);
        }

        for (int i = 0; i < M; ++i) {
            int element;
            std::cin >> element;
            B.add(element);
        }

        std::cout << union_bags(A, B) << std::endl;
        std::cout << intersect_bags(A, B) << std::endl;
        std::cout << A.difference(B) << std::endl;
        std::cout << B.difference(A) << std::endl;
    }

    return 0;
}
