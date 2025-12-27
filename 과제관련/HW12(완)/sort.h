#ifndef SORT_H
#define SORT_H
#include <algorithm>
using namespace std;

template <typename T>
void insertionSort(T* a, int n) {//삽입정렬-강의록참고
    for (int i = 1; i < n; i++) {
        T key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

template <typename T>
int partition(T* a, int left, int right) {//분할-강의록참고
    T pivot = a[left];
    int i = left - 1;
    int j = right + 1;

    while (true) {
        do { i++; } while (a[i] < pivot);
        do { j--; } while (a[j] > pivot);
        if (i >= j) return j;
        swap(a[i], a[j]);
    }
}

template <typename T>
void quickSort(T* a, int left, int right) {//퀵정렬-강의록참고
    if (left < right) {
        int p = partition(a, left, right);
        quickSort(a, left, p);
        quickSort(a, p + 1, right);
    }
}


template <typename T>
bool mergeRuns(T* a, T* temp, int n) {
    int i = 0;
    bool merged = false;

    while (i < n) {
        int left = i;

        while (i + 1 < n && a[i] <= a[i + 1]) i++;
        int mid = i;
        if (mid == n - 1) break;

        i++;
        while (i + 1 < n && a[i] <= a[i + 1]) i++;
        int right = i;

        int p = left, q = mid + 1, k = left;
        while (p <= mid && q <= right)
            temp[k++] = (a[p] <= a[q]) ? a[p++] : a[q++];
        while (p <= mid) temp[k++] = a[p++];
        while (q <= right) temp[k++] = a[q++];

        for (int t = left; t <= right; t++)
            a[t] = temp[t];

        merged = true;
        i++;
    }
    return merged;
}

template <typename T>
void naturalMergeSort(T* a, int n) {
    T* temp = new T[n];
    while (mergeRuns(a, temp, n));
    delete[] temp;
}





template <typename T>
void adjust(T* h, int root, int n) {
    T temp = h[root];
    int child = root * 2;

    while (child <= n) {
        if (child < n && h[child] < h[child + 1])
            child++;
        if (temp >= h[child]) break;
        h[root] = h[child];
        root = child;
        child *= 2;
    }
    h[root] = temp;
}

template <typename T>
void heapSort(T* a, int n) {//힙정렬
    
    T* h = new T[n + 1];
    for (int i = 0; i < n; i++)
        h[i + 1] = a[i];

    for (int i = n / 2; i >= 1; i--)
        adjust(h, i, n);

    for (int i = n; i >= 2; i--) {
        swap(h[1], h[i]);
        adjust(h, 1, i - 1);
    }

    for (int i = 0; i < n; i++)
        a[i] = h[i + 1];

    delete[] h;
}

#endif