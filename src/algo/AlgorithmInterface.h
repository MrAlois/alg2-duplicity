#ifndef ALG2_LOWERCASE_ALGORITHMINTERFACE_H
#define ALG2_LOWERCASE_ALGORITHMINTERFACE_H

#include <vector>
#include <algorithm>
#include <iostream>

class AlgorithmInterface {
public:
    virtual std::vector<std::string> process(std::vector<std::string>& data) = 0;
    virtual ~AlgorithmInterface() = default;
};

#endif //ALG2_LOWERCASE_ALGORITHMINTERFACE_H
