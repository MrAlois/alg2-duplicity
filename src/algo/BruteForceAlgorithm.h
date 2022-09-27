//
// Created by asenkyrik on 27.09.2022.
//

#ifndef ALG2_LOWERCASE_BRUTEFORCEALGORITHM_H
#define ALG2_LOWERCASE_BRUTEFORCEALGORITHM_H


#include "IAlgorithm.h"
#include "../AlgoUtils.h"

class BruteForceAlgorithm : public IAlgorithm{
public:
    BruteForceAlgorithm() = default;
    ~BruteForceAlgorithm() override {
        delete this;
    }

    std::vector<std::string> find_unique(const char* path) override {
        std::cout << "INFO: Using algorithm of type [BRUTE_FORCE] to find unique words in file." << std::endl;
        std::vector<std::string> vData;

        std::ifstream filestream = AlgoUtils::readFile(path);

        // Read data & brute check duplicity
        auto total_size = 0;
        for(std::string buffer; std::getline(filestream, buffer); total_size++) {
            if(std::find(vData.begin(), vData.end(), buffer) != vData.end()) continue;

            vData.push_back(buffer);
        }

        // Finish
        std::cout << "INFO: From total of {" << total_size << "} words found {" << vData.size() << "} that were unique." << std::endl;
        filestream.close();

        return vData;
    }
};

#endif //ALG2_LOWERCASE_BRUTEFORCEALGORITHM_H
