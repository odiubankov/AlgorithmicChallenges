#ifndef ALGORITHMICCHALLENGES_11_RANDOMNODE_H
#define ALGORITHMICCHALLENGES_11_RANDOMNODE_H
#include <memory>

class BstRandom {
public:
    struct Node {
        int val_ = 0;
        std::shared_ptr<Node> left_, right_;
        int leftChildrenCnt_ = 0;
        int rightChildrenCnt_ = 0;
        Node(int val) : val_{val} {}
    };

    void insert(int val);
    bool find(int val) const;
    void remove(int val);
    int getRandom() const;

private:
    static bool findImpl(const std::shared_ptr<Node>& node, int val);
    static void removeImpl(std::shared_ptr<Node>& node, int val);
    std::shared_ptr<Node> root_ = nullptr;
};

#endif //ALGORITHMICCHALLENGES_11_RANDOMNODE_H
