#include "linkedList.h"

int main(){
    std::vector<int> Arraylist = {1, 2};
    linkedList Newlist(Arraylist);
    Newlist.printList();
    Newlist.deleteFront();
    Newlist.printList();
    Newlist.deleteEnd();
    Newlist.printList();
    return 0;
}