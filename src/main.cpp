#include <iostream>
#include <vector>
#include <map>

#define MEASUREMENT 100

#include "../include/algorithms/mergesort.h"
#include "../include/algorithms/quicksort.h"
#include "../include/algorithms/heapsort.h"
#include "../include/algorithms/introsort.h"
#include "Experiment.hpp"


std::vector<int> getTestData() {
    return {47, 68, 23, 90, 36, 15, 52, 81, 10, 59}; /// Można modyfikować
}

std::vector<int> dataCount = {10000, 50000, 100000, 1000000};
std::vector<float> preSortValues = {25, 50, 75, 95, 99, 99.7f};


void first(
        const std::map<std::string, Algorithm<int>*>& algoritms,
        std::map<int, std::vector<long>*> results
) {
    for (const auto& element: algoritms) {


        for (int z = 0; z < MEASUREMENT; z++) {

            for (int i = 0; i < dataCount.size(); i++) {

                auto experimentData = Experiment::generateArray(dataCount[i]);

                Experiment::perform(
                        std::to_string(z) + ". Pomiar " + element.first + " " + std::to_string(i),
                        [&element, &experimentData]() {
                            element.second->sort(experimentData.begin(), experimentData.end());
                        },
                        results[dataCount[i]]
                );

            }
        }

        Experiment::buildCSV(element.first, results);

        results[10000]->clear();
        results[50000]->clear();
        results[100000]->clear();
        results[1000000]->clear();
    }
}

void sec(
        const std::map<std::string, Algorithm<int>*>& algoritms,
        std::map<int, std::vector<long>*> results
) {
    for (const auto& presort: preSortValues) {
        for (const auto& element: algoritms) {


            for (int z = 0; z < MEASUREMENT; z++) {

                for (int i = 0; i < dataCount.size(); i++) {

                    auto experimentData = Experiment::generateArray(dataCount[i]);
                    Experiment::preSort(experimentData, presort);

                    Experiment::perform(
                            std::to_string(z) +
                            ". Pomiar wstepnie sortowane w" + std::to_string(presort) + " % " +
                            element.first + " " + std::to_string(i),
                            [&element, &experimentData]() {
                                element.second->sort(experimentData.begin(), experimentData.end());
                            },
                            results[dataCount[i]]
                    );

                }
            }

            Experiment::buildCSV(std::to_string(presort) + " " + element.first, results);

            results[10000]->clear();
            results[50000]->clear();
            results[100000]->clear();
            results[1000000]->clear();
        }
    }
}


int main(int argc, char* argv[]) {

    std::map<int, std::vector<long>*> results;
    std::map<std::string, Algorithm<int>*> algoritms;

    QuickSort<int> quickSort{};
    IntroSort<int> introSort{};
    MergeSort<int> mergeSort{};


    algoritms["quicksort"] = &quickSort;
    algoritms["mergesort"] = &introSort;
    algoritms["introsort"] = &mergeSort;

    std::vector<long> timeResultsA;
    std::vector<long> timeResultsB;
    std::vector<long> timeResultsC;
    std::vector<long> timeResultsD;

    results[10000] = &timeResultsA;
    results[50000] = &timeResultsB;
    results[100000] = &timeResultsC;
    results[1000000] = &timeResultsD;

    sec(algoritms, results);

    return 0;
}


