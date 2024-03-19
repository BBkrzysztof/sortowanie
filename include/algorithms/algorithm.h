#pragma once
#include <vector>

template<typename T>
class Algorithm {
public:
    virtual void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) = 0;
};