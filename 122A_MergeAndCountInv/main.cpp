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
    std::cout << "-----------Initialize Begin---------" << std::endl;
    for (int i = 0; i < vecSize; ++i){
        TestVector.push_back(std::rand() % NUM_RANGE_);
        std::cout << i << ": " << TestVector[i] << std::endl;
    }
    std::cout << "-----------Initialize End-----------" << std::endl;
    std::cout << "-------------Test Begin-------------" << std::endl;
    int TestNum = 0;
    TestVector = SortAndCount(TestVector, &TestNum);
    for (int i = 0; i < int(TestVector.size()); ++i){
        std::cout << i << ": " << TestVector[i] << std::endl;
    }
    std::cout << "Number of Inversion: " <<TestNum << std::endl;
    std::cout << "-------------Test End---------------" << std::endl;
    return 0;
}