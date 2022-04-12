#include "linkedList.h"
#include <cstdlib>

#define INPUT_NUM 20
#define INPUT_RANGE 100

void RealGame(bool player, linkedList& TheList, bool Algo);
bool Strategy(std::vector<int>& Arraylist);

int main(){
    bool player = 0;
    // 0 represent Alice, 1 represent Bob; 
    int N = rand() % (INPUT_NUM / 2) + 1;
    N *= 2;
    std::vector<int> Arraylist;
    for (int i = 0; i < N; ++i){
        Arraylist.push_back(rand() % INPUT_RANGE);
    }
    linkedList Newlist(Arraylist);
    RealGame(player, Newlist, Strategy(Arraylist));
    return 0;
}

void RealGame(bool player, linkedList& TheList, bool Algo){
    // int Array[2] = {0, 0};
    TheList.printList();
    std::cout << "Strategy Finding: " << Algo << std::endl;
    return;
    while (!TheList.isEmpty()){
    }
}

bool Strategy(std::vector<int>& Arraylist){
    int Array[2] = {0, 0};
    for (size_t i = 0 ; i < Arraylist.size(); ++i){
        Array[i % 2] += Array[i];
    }
    return (Array[0] >= Array[1]);
}