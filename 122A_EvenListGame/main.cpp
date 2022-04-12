#include "linkedList.h"
#include <cstdlib>

#define INPUT_NUM 50
#define INPUT_RANGE 1000

void RealGame();
bool Strategy(std::vector<int>& Arraylist);

int main(){
    for (int i = 0; i < 30; ++i){
        RealGame();
        std::cout << "-------------------------" << std::endl;
    }
    return 0;
}

void RealGame(){
    bool player = 0;
    // 0 represent Alice, 1 represent Bob; 
    int N = rand() % (INPUT_NUM / 2) + 1;
    N *= 2;
    std::vector<int> Arraylist;
    for (int i = 0; i < N; ++i){
        Arraylist.push_back(rand() % INPUT_RANGE);
    }
    bool Algo = Strategy(Arraylist);
    linkedList Newlist(Arraylist);
    // initialization above;
    int Array[2] = {0, 0};
    while (!Newlist.isEmpty()){
        if (!player){
            Array[player] += (Algo) ? Newlist.findLastVal() : Newlist.findfirstVal();
            if (Algo)
                Newlist.deleteEnd();
            else
                Newlist.deleteFront();
        } else {
            int frontVal = Newlist.findfirstVal();
            int endVal = Newlist.findLastVal();
            if (frontVal > endVal){
                Array[player] += frontVal;
                Newlist.deleteFront();
                Algo = 0;
            } else {
                Array[player] += endVal;
                Newlist.deleteEnd();
                Algo = 1;
            }
        }
        player = !player;
    }
    // check win
    std::cout << "Alice: "<< Array[0];
    std::cout << "    Bob: "<< Array[1] << std::endl;
    if (Array[0] >= Array[1])
        std::cout << "Alice Wins!" << std::endl;
    else
        std::cout << "Bob Wins!" << std::endl;
}

bool Strategy(std::vector<int>& Arraylist){
    int Array[2] = {0, 0};
    for (size_t i = 0 ; i < Arraylist.size(); ++i){
        Array[i % 2] += Arraylist[i];
    }
    return (Array[0] < Array[1]);
}