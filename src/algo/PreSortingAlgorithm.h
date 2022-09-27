//
// Created by asenkyrik on 27.09.2022.
//

#ifndef ALG2_LOWERCASE_PRESORTINGALGORITHM_H
#define ALG2_LOWERCASE_PRESORTINGALGORITHM_H


#include "IAlgorithm.h"
#include "../AlgoUtils.h"

class PreSortingAlgorithm : public IAlgorithm{
public:
    PreSortingAlgorithm() = default;
    ~PreSortingAlgorithm() override {
        delete this;
    };

    std::vector<std::string> find_unique(const char* path) override {
        std::cout << "INFO: Using algorithm of type [PRE_SORTED] to find unique words in file." << std::endl;
        std::vector<std::string> vData;

        std::ifstream filestream = AlgoUtils::readFile(path);

        // Load Data
        for (std::string cache; std::getline(filestream, cache);)
            vData.push_back(cache);

        // Sort data
        auto total_size = vData.size();
        std::sort(vData.begin(), vData.end(), AlgoUtils::lexi_comparator);

        // Throw out data
        vData.erase( unique( vData.begin(), vData.end() ), vData.end());

        // Finish
        std::cout << "INFO: From total of {" << total_size << "} word found {" << vData.size() << "} that were unique." << std::endl;
        filestream.close();

        return vData;
    }
};

#endif //ALG2_LOWERCASE_PRESORTINGALGORITHM_H
