//
// Created by asenkyrik on 27.09.2022.
//

#ifndef ALG2_LOWERCASE_WORDPROCESSOR_H
#define ALG2_LOWERCASE_WORDPROCESSOR_H

#include <chrono>
#include <fstream>
#include "algo/AlgorithmInterface.h"

class WordProcessor {
public:
    WordProcessor() = default;
    ~WordProcessor() = default;

    /**
     * Filters all unique words based on provided algorithm.
     * @param filepath Path to file a file with newline-separated words.
     * @param algorithm Algorithm to be used for filtering.
     * @return All unique words in a vector of strings, else empty.
     */
    static std::vector<std::string> filter_unique(const char* filepath, AlgorithmInterface* algorithm){
        auto data = readFile(filepath);
        if(data.empty()){
            delete algorithm;
            return {};
        }

        auto start_time = std::chrono::high_resolution_clock::now();
        auto result = algorithm->process(data);
        auto elapsed_time = duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start_time).count();

        std::cout << "INFO: Total elapsed time - " << elapsed_time << "ms." << std::endl;

        delete algorithm;
        return result;
    }

private:
    /**
     * Reads the words from file and closes the stream.
     * @param path See above
     * @return Vector of string, otherwise empty vector if failed.
     */
    static std::vector<std::string> readFile(const char* path) {
        std::cout << "INFO: Using path \"" << path << "\" to open new filestream." << std::endl;

        std::ifstream filestream(path);
        if(!filestream.is_open()){
            std::cout << "ERROR: Couldn't open the filestream! Exiting.." << std::endl;
            return {};
        }

        std::vector<std::string> data;
        for (std::string cache; getline(filestream, cache);)
            data.push_back(cache);

        std::cout << "INFO: Words succesfully loaded! Total count: " << data.size() << std::endl;
        filestream.close();
        return data;
    }
};

#endif //ALG2_LOWERCASE_WORDPROCESSOR_H
