//
// Created by asenkyrik on 27.09.2022.
//

#ifndef ALG2_LOWERCASE_WORDHANDLER_H
#define ALG2_LOWERCASE_WORDHANDLER_H

#include <chrono>
#include "algo/IAlgorithm.h"

class WordHandler {
private:
    IAlgorithm* _current_algorithm = nullptr;

public:
    ~WordHandler() {
        delete this->_current_algorithm;
    }

    explicit WordHandler(IAlgorithm& algorithm) {
        setAlgorithm(algorithm);
    }

    std::vector<std::string> getUniqueWords(const char* filepath){
        if(_current_algorithm == nullptr)
            return {};

        auto start_time = std::chrono::high_resolution_clock::now();
        auto result = _current_algorithm->find_unique(filepath);

        std::cout << "INFO: Total elapsed time - " << duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start_time).count() << " ms." << std::endl;
        return result;
    }

    void setAlgorithm(IAlgorithm& algorithm) {
        delete this->_current_algorithm;
        this->_current_algorithm = &algorithm;
    }
};

#endif //ALG2_LOWERCASE_WORDHANDLER_H
