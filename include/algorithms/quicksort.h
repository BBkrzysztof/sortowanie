#ifndef SORTING_ALGORITHMS_QUICKSORT_H
#define SORTING_ALGORITHMS_QUICKSORT_H

#include <vector>
#include <random>
#include "algorithm.h"
// quicksort

template<typename T>
class QuickSort: public Algorithm<T> {
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {

        if (start < (end - 1)) {
            auto middle = sortNonRecursive(start, end);

            sort(start, middle);
            sort((middle + 1), end);
        }
    };

    typename std::vector<T>::iterator sortNonRecursive(
            typename std::vector<T>::iterator start,
            typename std::vector<T>::iterator end
    ) {

        std::random_device rd;
        std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<int> dist(0, std::distance(start, end));

        auto pivot = start + dist(gen);

        auto i = (start - 1);

        for (typename std::vector<T>::iterator j = start; j != end; ++j) {
            if (*j < *pivot) {
                ++i;
                std::swap(*j, *i);
                std::swap(*j, *j);
            }
        }
        ++i;

        std::swap(*i, *pivot);


        return start + (std::distance(start, i));
    }
};

#endif //SORTING_ALGORITHMS_QUICKSORT_H
