#define CATCH_CONFIG_MAIN
#include "../include/catch2/catch.hpp"

#include "../include/algorithms/bubblesort.h"
#include "../include/algorithms/heapsort.h"
#include "../include/algorithms/mergesort.h"
#include "../include/algorithms/quicksort.h"
#include "../include/algorithms/introsort.h"

using namespace std::string_literals;

std::vector<int> getTestData()
{
    return {11,102,1,13,25,18,20,7,8,6,103,3,1}; /// Można modyfikować
}

std::vector<int> getSortedData()
{
    auto data = getTestData();
    std::sort(data.begin(),data.end());
    return data;
}

TEST_CASE("HeapSort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    HeapSort<int> heapSort;
    heapSort.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}

TEST_CASE("MergeSort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    MergeSort<int> mergeSort;
    mergeSort.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}

TEST_CASE("QuickSort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    QuickSort<int> quickSort;
    quickSort.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}

TEST_CASE("IntroSort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    IntroSort<int> introSort{};
    introSort.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}
//TEST_CASE("BubbleSort")
//{
//    auto data = getTestData();
//    auto resultData = getSortedData();
//
//    BubbleSort<int> bubbleSort;
//    bubbleSort.sort(data.begin(),data.end());
//
//    REQUIRE(data == resultData);
//}

//TEST_CASE("InsertSort")
//{
//    auto data = getTestData();
//    auto resultData = getSortedData();
//
//    InsertSort<int> insertSort;
//    insertSort.sort(data.begin(),data.end());
//
//    REQUIRE(data == resultData);
//}

//TEST_CASE("ShellSort")
//{
//    auto data = getTestData();
//    auto resultData = getSortedData();
//
//    ShellSort<int> shellSort;
//    shellSort.sort(data.begin(),data.end());
//
//    REQUIRE(data == resultData);
//}
//

