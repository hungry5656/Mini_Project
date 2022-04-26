#include "MergeAndCount.h"
#include <string> // string
#include <iostream> // cout
#include <cstdlib> // rand()
#include <vector> // vector
#define NUM_RANGE_ 99
#define VEC_SIZE_ 99

int main(){
    int vecSize = std::rand() % VEC_SIZE_;
    std::vector<int> TestVector;
    for (int i = 0; i < vecSize; ++i){
        TestVector.push_back(std::rand() % NUM_RANGE_);
        std::cout << TestVector[i] << std::endl;
    }
    
    return 0;
}