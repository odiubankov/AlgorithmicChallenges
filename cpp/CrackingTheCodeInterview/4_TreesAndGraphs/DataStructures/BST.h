#ifndef ALGORITHMICCHALLENGES_BST_H
#define ALGORITHMICCHALLENGES_BST_H

#include <memory>

class BstNode{
public:
    std::shared_ptr<BstNode> left_;
    std::shared_ptr<BstNode> right_;
    int val_{0};
};

class Bst{
public:
    std::shared_ptr<BstNode> head_;
};

#endif //ALGORITHMICCHALLENGES_BST_H
