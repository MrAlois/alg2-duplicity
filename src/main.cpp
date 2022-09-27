#include <iostream>
#include <vector>

#include "WordProcessor.h"
#include "algo/BruteForceAlgorithm.h"
#include "algo/PreSortingAlgorithm.h"


int main() {
    const char* c_file_path = "../WordsLowercase.txt";
    std::cout << "Algorithms II - HW I: Select distinct from a set of words." << std::endl;

    WordProcessor::filter_unique(c_file_path, new BruteForceAlgorithm); std::cout << std::endl;
    WordProcessor::filter_unique(c_file_path, new PreSortingAlgorithm);

    return 0;
}


