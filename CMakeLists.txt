cmake_minimum_required(VERSION 3.23)
project(alg2-lowercase)

set(CMAKE_CXX_STANDARD 23)

add_executable(alg2-lowercase src/main.cpp src/algo/AlgorithmInterface.h src/WordProcessor.h src/algo/BruteForceAlgorithm.h src/algo/PreSortingAlgorithm.h)
