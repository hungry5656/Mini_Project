#include "linkedList.h"

linkedListNode::linkedListNode(int val):
    value(val),
    parent_(std::weak_ptr<linkedListNode>()),
    child_(nullptr){}

linkedListNode::linkedListNode(int val, std::weak_ptr<linkedListNode> parent):
    value(val),
    parent_(parent),
    child_(nullptr){}

void linkedListNode::replaceNode(std::shared_ptr<linkedListNode> ANode, std::shared_ptr<linkedListNode> BNode){
    if (child_ == BNode){
        std::cerr << "linkedListNode::replaceNode Error: replacement is already the child";
    }
    child_ = BNode;
    BNode -> parent_ = ANode -> parent_;
}

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
    }
}

void linkedList::insert(int val){
    if (root == nullptr) {
		root = std::make_shared<linkedListNode>(val);
		size_++;
		return;
	}
    std::shared_ptr<linkedListNode> currentNode = root;
    while (!currentNode -> isEnd()){
        currentNode = currentNode -> child_;
    }
    currentNode -> child_ = std::make_shared<linkedListNode>(val);
    ++size_;
}

int linkedList::findfirstVal() const{
    return root -> value;
}

void linkedList::deleteFront(){
    root = root -> child_;
    root -> parent_.reset();
    --size_;
}

void linkedList::deleteEnd(){
    std::shared_ptr<linkedListNode> currentNode = root;
    while (!currentNode -> isEnd()){
        currentNode = currentNode -> child_;
    }
    std::shared_ptr<linkedListNode> parent = currentNode -> parent_.lock();
    // parent -> replaceNode(currentNode, nullptr);
    parent -> child_ = nullptr;
    --size_;
}

int linkedList::findLastVal() const{
    if (root == nullptr) return -1;
    std::shared_ptr<linkedListNode> currentNode = root;
    while (!currentNode -> isEnd()){
        currentNode = currentNode -> child_;
    }
    return currentNode -> value;
}

size_t linkedList::size() const{
    return size_;
}

void linkedList::printList() const{
    std::shared_ptr<linkedListNode> currentNode = root;
    for (int i = 0; i < size_; ++i){
        std::cout << "Number " << i+1 << " Node: " << currentNode -> value << std::endl;
        currentNode = currentNode -> child_;
    }
}
