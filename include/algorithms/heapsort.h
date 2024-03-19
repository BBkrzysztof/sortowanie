#ifndef SORTING_ALGORITHMS_HEAPSORT_H
#define SORTING_ALGORITHMS_HEAPSORT_H

#include <vector>

// sortowanie przez kopcowanie. Należy samodzielnie zaimplementować odpowiedni kopiec, który kopcuje bez użycia dodatkowej pamięci.

template<typename T>
class HeapSort {
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {

        int n = end - start;

        // Budowanie kopca
        for (auto i = start + n / 2 - 1; i >= start; --i)
            this->heapify(start, end, i);

        // Wyciąganie elementów z kopca
        for (auto i = end - 1; i > start; --i) {
            std::swap(*start, *i);
            this->heapify(start, i, start);
        }
    };
public:
    void heapify(
            typename std::vector<T>::iterator begin,
            typename std::vector<T>::iterator end,
            typename std::vector<T>::iterator root
    ) {
        auto largest = root;
        auto left = begin + 2 * (root - begin) + 1;
        auto right = begin + 2 * (root - begin) + 2;

        if (left < end && *left > *largest)
            largest = left;

        if (right < end && *right > *largest)
            largest = right;

        if (largest != root) {
            std::swap(*root, *largest);
            this->heapify(begin, end, largest);
        }
    }
};

#endif //SORTING_ALGORITHMS_HEAPSORT_H
