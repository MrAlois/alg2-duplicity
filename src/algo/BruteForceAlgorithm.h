//
// Created by asenkyrik on 27.09.2022.
//

#ifndef ALG2_LOWERCASE_BRUTEFORCEALGORITHM_H
#define ALG2_LOWERCASE_BRUTEFORCEALGORITHM_H

#include "AlgorithmInterface.h"

class BruteForceAlgorithm : public AlgorithmInterface{
public:
    BruteForceAlgorithm() = default;
    ~BruteForceAlgorithm() override = default;

    std::vector<std::string> process(std::vector<std::string>& data) override {
        std::cout << "INFO: Using algorithm of type [BRUTE_FORCE] to find all unique words in file." << std::endl;

        std::vector<std::string> result;
        for(const auto& text : data){
            if(std::find(result.begin(), result.end(), text) != result.end()) continue;
            result.push_back(text);
        }

        std::cout << "INFO: From total of " << data.size() << " words, " << result.size() << " of them were unique." << std::endl;
        return result;
    }
};

#endif //ALG2_LOWERCASE_BRUTEFORCEALGORITHM_H
