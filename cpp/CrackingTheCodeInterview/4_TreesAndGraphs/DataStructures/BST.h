#ifndef ALGORITHMICCHALLENGES_BST_H
#define ALGORITHMICCHALLENGES_BST_H

#include <memory>

class BstNode;
using BstNodePtr = std::shared_ptr<BstNode>;

class BstNode{
public:
    BstNode(int val)
        : val_{val}
    {}
    BstNode() = default;

    BstNodePtr left_;
    BstNodePtr right_;
    int val_{0};
};

class Bst{
public:
    BstNodePtr head_;
};

#endif //ALGORITHMICCHALLENGES_BST_H
