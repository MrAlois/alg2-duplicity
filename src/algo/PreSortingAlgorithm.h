//
// Created by asenkyrik on 27.09.2022.
//

#ifndef ALG2_LOWERCASE_PRESORTINGALGORITHM_H
#define ALG2_LOWERCASE_PRESORTINGALGORITHM_H

#include "AlgorithmInterface.h"

class PreSortingAlgorithm : public AlgorithmInterface{
public:
    PreSortingAlgorithm() = default;
    ~PreSortingAlgorithm() override = default;

    std::vector<std::string> process(std::vector<std::string>& data) override {
        std::cout << "INFO: Using algorithm of type [PRE_SORTED] to find all unique words in file." << std::endl;

        auto result = data;
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());

        std::cout << "INFO: From total of " << data.size() << " words, " << result.size() << " of them were unique." << std::endl;
        return result;
    }
};

#endif //ALG2_LOWERCASE_PRESORTINGALGORITHM_H
