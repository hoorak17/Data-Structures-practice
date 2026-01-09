#include <algorithm>
#include <iostream>
#include <vector>

#include "ArrayBag.h"
//구현 필요
template <typename T>
ArrayBag<T>::ArrayBag() : item_cnt(0), max_items(DEFAULT_CAPACITY) {}

template <typename T>
ArrayBag<T>::ArrayBag(int capacity) : item_cnt(0), max_items(capacity) {}

template <typename T>
int ArrayBag<T>::get_current_size() const {
}

template <typename T>
bool ArrayBag<T>::is_empty() const {
}

template <typename T>
bool ArrayBag<T>::add(const T& newEntry) {
}

template <typename T>
bool ArrayBag<T>::remove(const T& anEntry) {
}

template <typename T>
void ArrayBag<T>::clear() {
}

template <typename T>
bool ArrayBag<T>::contains(const T& anEntry) const {
}

template <typename T>
int ArrayBag<T>::get_frequency_of(const T& anEntry) const {
}

template <typename T>
std::vector<T> ArrayBag<T>::to_vector() const {
}

template <typename T>
int ArrayBag<T>::get_index_of(const T& target) const {
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const ArrayBag<U>& bag) {
    std::vector<U> items(bag.to_vector());
    std::sort(items.begin(), items.end());

    for (const U& item : items) {
        os << item << " ";
    }
    return os;
}

template <typename T>
ArrayBag<T> union_bags(const ArrayBag<T>& bag1, const ArrayBag<T>& bag2) {
}

template <typename T>
ArrayBag<T> intersect_bags(const ArrayBag<T>& bag1, const ArrayBag<T>& bag2) {
}

template <typename T>
ArrayBag<T> ArrayBag<T>::difference(const ArrayBag<T>& another_bag) const {
}
