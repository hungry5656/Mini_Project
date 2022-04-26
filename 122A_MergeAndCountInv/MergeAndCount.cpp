#include "MergeAndCount.h"


std::vector<int> MergeAndCount(std::vector<int> A, std::vector<int> B, int* NumInv){
    /*
    ** This function Merge the vector and count the number of inversion
    */

    std::vector<int> List;
    int iMax = A.size(), jMax = B.size();
    int i = 0, j = 0;
    while(!(i == iMax && j == jMax)){
        // std::cout << "Bruh!\n";
        if (i == iMax){
            List.push_back(B[j]);
            ++j;
        } else if (j == jMax){
            List.push_back(A[i]);
            ++i;
        } else {
            if (A[i] < B[j]){
                List.push_back(A[i]);
                ++i;
            } else {
                List.push_back(B[j]);
                ++j;
                *NumInv = *NumInv + iMax - i;
            }
        }
    }
    return List;
}

std::vector<int> SortAndCount(std::vector<int> List, int* NumInv){
    if (List.size() == 1){
        return List;
    }
    int currSize = List.size();
    int HalfIndex = currSize / 2;

    std::vector<int> A(List.begin(), List.begin() + HalfIndex);
    // for (int m = 0 ; m < int(A.size()); ++m){
    //     std::cout << A[m] << std::endl;
    // }
    // std::cout << "--------------------------" << std::endl;
    std::vector<int> B(List.begin() + HalfIndex, List.begin() + List.size());
    // for (int m = 0 ; m < int(B.size()); ++m){
    //     std::cout << B[m] << std::endl;
    // }
    A = SortAndCount(A, NumInv);
    B = SortAndCount(B, NumInv);
    List = MergeAndCount(A, B, NumInv);
    return List;
}