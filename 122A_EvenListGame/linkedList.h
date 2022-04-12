#include <memory>
#include <string>
#include <vector>
#include <iostream>

class linkedListNode{
    public:
        linkedListNode(int val);
        linkedListNode(int val, std::weak_ptr<linkedListNode> parent);
        void deletChild();
        void replaceNode(std::shared_ptr<linkedListNode> ANode, std::shared_ptr<linkedListNode> BNode);
        bool isEnd();

    private:
        std::weak_ptr<linkedListNode> parent_;
        std::shared_ptr<linkedListNode> child_;
        int value;
    
    friend linkedList;
};

class linkedList{
    public:
        linkedList();
        linkedList(int val);
        linkedList(std::vector<int> vec);

        void insert(int val);
        void deleteFront();
        void deleteEnd();
        int findfirstVal() const;
        int findLastVal() const;
        size_t size() const;
        void printList() const;

    private:
        std::shared_ptr<linkedListNode> root;
        size_t size_;
};
