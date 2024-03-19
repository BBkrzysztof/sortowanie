#ifndef SORTING_ALGORITHMS_MERGESORT_H
#define SORTING_ALGORITHMS_MERGESORT_H

#include <vector>
#include "algorithm.h"

// sortowanie przez scalanie

template<typename T>
class MergeSort : public Algorithm<T> {
public:

    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        typename std::vector<T>::iterator middle = start + (std::distance(start, end) / 2);

        if (start < (end - 1)) {
            sort(start, middle);
            sort(middle, end);
            merge(start, middle, end);
        }
    };

private:
    void merge(
            typename std::vector<T>::iterator begin,
            typename std::vector<T>::iterator mid,
            typename std::vector<T>::iterator end
    ) {

        std::vector<T> left(begin, mid);
        std::vector<T> right(mid, end);

        auto left_iter = left.begin();
        auto right_iter = right.begin();
        auto dest_iter = begin;

        while (left_iter != left.end() && right_iter != right.end()) {
            if (*left_iter < *right_iter) {
                *dest_iter++ = *left_iter++;
            } else {
                *dest_iter++ = *right_iter++;
            }
        }

        while (left_iter != left.end()) {
            *dest_iter++ = *left_iter++;
        }

        while (right_iter != right.end()) {
            *dest_iter++ = *right_iter++;
        }
    }
};

#endif //SORTING_ALGORITHMS_MERGESORT_H
