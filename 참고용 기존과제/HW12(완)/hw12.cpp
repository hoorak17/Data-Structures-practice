#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include <sys/time.h>
#include <algorithm>   // copy쓸라고 추가
#include "sort.h"

using namespace std;

static inline double elapsed_sec(const timeval& start_t, const timeval& end_t) {
    return (double)(end_t.tv_sec - start_t.tv_sec) +
           (double)(end_t.tv_usec - start_t.tv_usec) / 1000000.0;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "wrong argument count" << endl;
        cerr << "usage: hw12 <T> file1 file2 ..." << endl;
        return 1;
    }

    int T = atoi(argv[1]);
    cout << "T=" << T << endl;

    if (argc < T + 2) { 
        cerr << "wrong argument count: expected " << (T + 2)
             << " args but got " << argc << endl;
        return 1;
    }

    int N;   
    double result[4]; 

    struct timeval start_t, end_t;
    double diff_t;

    cout << "--INS--|--QUICK--|--NATMG--|--HEAP--|" << endl;

    for (int i = 2; i < T + 2; i++) {
        
        ifstream fin(argv[i]);
        if (!fin.is_open()) {
            cerr << "Failed to open file: " << argv[i] << endl;
            return 1;
        }

        fin >> N; 
        if (!fin || N <= 0) {
            cerr << "Invalid N in file: " << argv[i] << endl;
            return 1;
        }

        int* A = new int[N];
        for (int k = 0; k < N; k++) {
            fin >> A[k];
            if (!fin) {
                cerr << "Not enough data in file: " << argv[i] << endl;
                delete[] A;
                return 1;
            }
        }
        fin.close();

        int* B = new int[N];
        int* C = new int[N];
        int* D = new int[N];
        copy(A, A + N, B);
        copy(A, A + N, C);
        copy(A, A + N, D);

        gettimeofday(&start_t, NULL);
        insertionSort(A, N);
        gettimeofday(&end_t, NULL);
        diff_t = elapsed_sec(start_t, end_t);
        result[0] = diff_t;

        gettimeofday(&start_t, NULL);
        quickSort(B, 0, N - 1);
        gettimeofday(&end_t, NULL);
        diff_t = elapsed_sec(start_t, end_t);
        result[1] = diff_t;

        gettimeofday(&start_t, NULL);
        naturalMergeSort(C, N);
        gettimeofday(&end_t, NULL);
        diff_t = elapsed_sec(start_t, end_t);
        result[2] = diff_t;

        gettimeofday(&start_t, NULL);
        heapSort(D, N);
        gettimeofday(&end_t, NULL);
        diff_t = elapsed_sec(start_t, end_t);
        result[3] = diff_t;

        delete[] A;
        delete[] B;
        delete[] C;
        delete[] D;

        /* 결과를 출력합니다. (이 부분은 수정하지 않습니다) */
        cout.precision(5);
        cout << fixed;
        for (int j = 0; j < 4; j++) {
            cout << result[j] << "|";
        }
        cout << "N=" << N << endl;
    }

    return 0;
}