#define CATCH_CONFIG_MAIN

#include "../include/catch2/catch.hpp"
#include <vector>
#include "Experiment.hpp"


const std::vector<int> twentyFivePercents = {47, 68, 23, 90, 36, 15, 52, 81, 10, 59};

const std::vector<int> fiftyPercents = {23, 36, 47, 68, 90, 15, 52, 81, 10, 59};

const std::vector<int> seventySixPercents = {15, 23, 36, 47, 52, 68, 90, 81, 10, 59};

std::vector<int> getTestArray() {
    std::vector<int> array = {47, 68, 23, 90, 36, 15, 52, 81, 10, 59};
    return array;
}

TEST_CASE("Pre sort 25%")
{
    std::vector<int> array = getTestArray();
    Experiment::preSort<int>(array, 25);


    REQUIRE(array == twentyFivePercents);
}

TEST_CASE("Pre sort 50%")
{
    std::vector<int> array = getTestArray();
    Experiment::preSort<int>(array, 50);


    REQUIRE(array == fiftyPercents);
}

TEST_CASE("Pre sort 76%")
{
    //should 76% of 10 elements array should round to 7 elments
    std::vector<int> array = getTestArray();
    Experiment::preSort<int>(array, 76);


    REQUIRE(array == seventySixPercents);
}

