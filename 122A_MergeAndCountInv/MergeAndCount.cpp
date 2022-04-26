#include "MergeAndCount.h"

std::vector<int> MergeAndCount(std::vector<int> A, std::vector<int> B, int* NumInv){
    /*
    ** This function Merge the vector and count the number of inversion
    */
    
}

std::vector<int> SortAndCount(std::vector<int> List, int* NumInv){
    if (List.size() == 1){
        return List;
    }
    int currSize = List.size();
    int HalfIndex = currSize / 2;

    std::vector<int> A(List.begin(), List.begin() + HalfIndex);
    std::vector<int> B(List.begin() + HalfIndex + 1, List.end());
    A = SortAndCount(A, NumInv);
    B = SortAndCount(B, NumInv);
    List = MergeAndCount(A, B)
}