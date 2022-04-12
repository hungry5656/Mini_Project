#include "linkedList.h"

linkedListNode::linkedListNode(int val):
    value(val),
    parent_(std::weak_ptr<linkedListNode>()),
    child_(nullptr){}

linkedListNode::linkedListNode(int val, std::weak_ptr<linkedListNode> parent):
    value(val),
    parent_(parent),
    child_(nullptr){}

bool linkedListNode::isEnd(){
    return child_ == nullptr;
}

linkedList::linkedList():
    root(nullptr),
    size_(0){}

linkedList::linkedList(std::vector<int> vec){
    size_ = 0;
    for(auto itr = vec.begin(); itr != vec.end(); ++itr){
        insert(*itr);
        ++size_;
    }
}

void linkedList::insert(int val){
    if (root == nullptr) {
		root = std::make_shared<linkedListNode>(val);
		size_++;
		return;
	}
}

int linkedList::findfirst() const{
    return root -> value;
}

void linkedList::deleteFront(){
    
}

void linkedList::deleteEnd(){

}

int linkedList::findLast() const{
    if (root == nullptr) return -1;
    std::shared_ptr<linkedListNode> currentNode = root;
    while (!currentNode->isEnd()){
        currentNode = currentNode -> child_;
    }
    return currentNode -> value;
}

size_t linkedList::size() const{
    return size_;
}
