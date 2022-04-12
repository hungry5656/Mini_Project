#include "linkedList.h"

int main(){
    std::vector<int> Arraylist = {1, 2, 3, 4, 5, 6};
    linkedList Newlist(Arraylist);
    Newlist.printList();
    return 0;
}