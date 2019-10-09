//https://leetcode.com/problems/subtree-of-another-tree/
#ifndef ALGORITHMICCHALLENGES_10_CHECKSUBTREE_H
#define ALGORITHMICCHALLENGES_10_CHECKSUBTREE_H

#include "DataStructures/TreeNode.h"
#include <queue>

class SolutionIsSubtree {
    bool areEqual(TreeNode* left, TreeNode* right) {
        std::queue<TreeNode*> leftNodes, rightNodes;
        leftNodes.push(left);
        rightNodes.push(right);
        while (!leftNodes.empty() && !rightNodes.empty()) {
            auto leftNode = leftNodes.front();
            auto rightNode = rightNodes.front();
            if (leftNode->val != rightNode->val)
                return false;
            leftNodes.pop();
            rightNodes.pop();
            if (leftNode->left)
                leftNodes.push(leftNode->left);
            if (leftNode->right)
                leftNodes.push(leftNode->right);
            if (rightNode->left)
                rightNodes.push(rightNode->left);
            if (rightNode->right)
                rightNodes.push(rightNode->right);
        }
        return leftNodes.empty() && rightNodes.empty();
    }

public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (t == nullptr)
            return true;
        if (s == nullptr)
            return false;
        std::queue<TreeNode*> nodes;
        nodes.push(s);
        while (!nodes.empty()) {
            auto node = nodes.front();
            if (areEqual(node, t))
                return true;
            nodes.pop();
            if (node->left)
                nodes.push(node->left);
            if (node->right)
                nodes.push(node->right);
        }
        return false;
    }
};

#endif //ALGORITHMICCHALLENGES_10_CHECKSUBTREE_H
