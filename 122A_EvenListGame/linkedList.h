#include <memory>
#include <string>
#include <vector>

class linkedListNode{
    public:
        linkedListNode(int val);
        linkedListNode(int val, std::weak_ptr<linkedListNode> parent);

        bool isEnd();

    private:
        std::weak_ptr<linkedListNode> parent_;
        std::shared_ptr<linkedListNode> child_;
    friend linkedList;
};

class linkedList{
    public:
        linkedList(std::vector<int> vec);

        void insert(int val);
        int findfirst() const;
        int findLast() const;
        size_t size() const;

    private:
        std::shared_ptr<linkedListNode> root;
        size_t size_;
};
