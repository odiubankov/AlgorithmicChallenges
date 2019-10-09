//https://leetcode.com/problems/inorder-successor-in-bst/
#ifndef ALGORITHMICCHALLENGES_6_SUCCESSOR_H
#define ALGORITHMICCHALLENGES_6_SUCCESSOR_H

#include "DataStructures/TreeNode.h"

class SolutionInorderSuccessor {
    TreeNode* inorderSuccessorImpl(TreeNode* node, TreeNode* p, TreeNode* rightParent) {
        if (!node)
            return nullptr;
        if (node == p) {
            if (node->right) {
                auto smallestRight = node->right;
                while (smallestRight->left)
                    smallestRight = smallestRight->left;
                return smallestRight;
            }
            return rightParent;
        }
        if (p->val < node->val) {
            return inorderSuccessorImpl(node->left, p, node);
        }
        return inorderSuccessorImpl(node->right, p, rightParent);
    }

public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!p)
            return nullptr;
        return inorderSuccessorImpl(root, p, nullptr);
    }
};
#endif //ALGORITHMICCHALLENGES_6_SUCCESSOR_H
