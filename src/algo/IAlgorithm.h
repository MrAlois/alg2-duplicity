#ifndef ALG2_HOMEWORK_IALGORITHM_H
#define ALG2_HOMEWORK_IALGORITHM_H

#include <iostream>
#include <vector>

class IAlgorithm {
public:
    virtual std::vector<std::string> find_unique(const char* path) = 0;
    virtual ~IAlgorithm() = default;
};

#endif //ALG2_HOMEWORK_IALGORITHM_H
