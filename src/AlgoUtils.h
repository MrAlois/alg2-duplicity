//
// Created by asenkyrik on 27.09.2022.
//

#ifndef ALG2_LOWERCASE_ALGOUTILS_H
#define ALG2_LOWERCASE_ALGOUTILS_H

#include <iostream>
#include <vector>
#include <fstream>

class AlgoUtils{
public:
    static bool lexi_comparator(const std::string& a, const std::string& b){
        if (a.compare(0, b.size(), b) == 0 || b.compare(0, a.size(), a) == 0)
            return a.size() > b.size();
        else
            return a < b;
    }

    static std::ifstream readFile(const char* path) {
        std::cout << "INFO: Using file_path \"" << path << "\" to open new file." << std::endl;

        std::ifstream file(path);
        if(!file.is_open()){
            std::cout << "ERROR: Couldn't open the file! exiting.." << std::endl;
            return {};
        }

        return file;
    }
};

#endif //ALG2_LOWERCASE_ALGOUTILS_H
