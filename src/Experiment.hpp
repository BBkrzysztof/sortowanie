#pragma onc

#include <chrono>
#include <iostream>
#include <fstream>
#include <functional>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <ctime>
#include <iomanip>
#include <random>
#include <limits>

#include "../include/algorithms/introsort.h"
#include "../include/algorithms/mergesort.h"
#include "../include/algorithms/quicksort.h"
#include "../include/algorithms/heapsort.h"

class Experiment {
public:

    static const std::string LOG_PATH;


    static std::vector<int> generateArray(const int size) {
        std::random_device rd;
        std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);
        std::vector<int> numbers;

        for (int i = 0; i < size; ++i) {
            numbers.push_back(dist(gen));
        }

        return numbers;
    }

    template<typename T>
    static void preSort(std::vector<T>& data, const float percent) {
        const float realPercent = percent / 100;

        auto start = data.begin();

        const unsigned int brakePointShift = std::floor(std::distance(start, data.end()) * realPercent);

        auto brakePoint = start + brakePointShift;

        IntroSort<T> introSort{};
        introSort.sort(start, brakePoint);
    }

    static void buildCSV(const std::string& name, const std::map<int, std::vector<long>*>& data) {
        std::stringstream fileName;
        fileName << LOG_PATH << name << ".csv";
        auto d = fileName.str();
        std::fstream log(fileName.str(), std::ios::out);

        for (auto element: data) {
            log << std::to_string(element.first) << ";";
        }
        log << "\n";

        for (int i = 0; i < MEASUREMENT; i++) {
            for (auto key: data) {
                log << std::to_string((*key.second)[i]) << ";";
            }
            log << "\n";
        }

        log.close();
    }

    static void perform(
            const std::string& experimentName,
            const std::function<void()>& experiment,
            std::vector<long>* results = nullptr,
            bool saveInFile = false
    ) {
        auto start = std::chrono::high_resolution_clock::now();

        experiment();

        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        std::stringstream msg;

        msg << "Pomiar: " << experimentName << " wykonywal sie przez: " << duration.count() << " ms \n";

        std::cout << msg.str() << std::endl;

        if (results != nullptr) {
            results->push_back((long) duration.count());
        }

        if (saveInFile) {

            std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

            std::time_t now_c = std::chrono::system_clock::to_time_t(now);

            std::tm* now_tm = std::localtime(&now_c);

            auto date = std::put_time(now_tm, "%Y-%m-%dT%H-%M-%S");

            std::stringstream fileName;
            fileName << LOG_PATH << experimentName << " " << date << ".txt";
            auto d = fileName.str();
            std::fstream log(fileName.str(), std::ios::out);
            log << msg.str();
            log.close();
        }

    }
};

const std::string Experiment::LOG_PATH = "./logs/";