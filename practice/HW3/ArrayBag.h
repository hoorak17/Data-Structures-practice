#ifndef ARRAY_BAG_H
#define ARRAY_BAG_H

#include <iostream>
#include <vector>

template <typename T>
class ArrayBag {
private:
    static const int DEFAULT_CAPACITY = 100;
    T items[DEFAULT_CAPACITY];
    int item_cnt;
    int max_items;

    int get_index_of(const T&) const;

public:
    ArrayBag();
    ArrayBag(int);

    int get_current_size() const;
    bool is_empty() const;
    bool add(const T&);
    bool remove(const T&);
    void clear();
    bool contains(const T&) const;
    int get_frequency_of(const T&) const;
    std::vector<T> to_vector() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const ArrayBag<U>&);

    template <typename U>
    friend ArrayBag<U> union_bags(const ArrayBag<U>&, const ArrayBag<U>&);

    template <typename U>
    friend ArrayBag<U> intersect_bags(const ArrayBag<U>&, const ArrayBag<U>&);

    ArrayBag<T> difference(const ArrayBag<T>&) const;
};

template <typename T>
ArrayBag<T> union_bags(const ArrayBag<T>&, const ArrayBag<T>&);

template <typename T>
ArrayBag<T> intersect_bags(const ArrayBag<T>&, const ArrayBag<T>&);

#include "ArrayBag.cpp"

#endif
