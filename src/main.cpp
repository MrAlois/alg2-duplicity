#include <iostream>
#include <vector>

#include "WordHandler.h"
#include "algo/BruteForceAlgorithm.h"
#include "algo/PreSortingAlgorithm.h"

const char *file_path = "../WordsLowercase.txt";

int main() {
    std::cout << "Algorithms II - HW I: Select distinct from a set of words." << std::endl;

    WordHandler handler(*new BruteForceAlgorithm());
    handler.getUniqueWords(file_path);

    handler.setAlgorithm(*new PreSortingAlgorithm());
    handler.getUniqueWords(file_path);

    return 0;
}


