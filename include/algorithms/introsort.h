#ifndef SORTING_ALGORITHMS_INTROSORT_H
#define SORTING_ALGORITHMS_INTROSORT_H

#include <vector>
#include <iostream>
#include <cmath>
#include "heapsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "algorithm.h"

// sortowanie introspektywne

template<typename T>
class IntroSort : public Algorithm<T> {
public:

    IntroSort() = default;

    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        const int size = std::distance(start, end);
        const int maxDepth = 2 * log(size);

        this->helper(start, end, maxDepth);
        this->mergeSort.sort(start, end);
    };

private:
    void helper(
            typename std::vector<T>::iterator start,
            typename std::vector<T>::iterator end,
            int maxDepth
    ) {
        if (end - start) {
            return;
        }

        if (maxDepth == 0) {
            this->heapSort.sort(start, end);
        } else {
            --maxDepth;
            auto pivot = this->quickSort.sortNonRecursive(start, end);
            this->helper(start, pivot, maxDepth);
            this->helper((pivot + 1), end, maxDepth);
        }
    }

private:
    HeapSort<T> heapSort;
    MergeSort<T> mergeSort;
    QuickSort<T> quickSort;
};

#endif //SORTING_ALGORITHMS_INTROSORT_H
