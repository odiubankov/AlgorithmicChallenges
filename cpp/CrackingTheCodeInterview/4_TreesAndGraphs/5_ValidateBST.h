//https://leetcode.com/problems/validate-binary-search-tree/
#ifndef ALGORITHMICCHALLENGES_5_VALIDATEBST_H
#define ALGORITHMICCHALLENGES_5_VALIDATEBST_H

#include "DataStructures/TreeNode.h"
#include <limits>

class Solution {
    bool isValidBstImpl(TreeNode* node, int min, int max) {
        if (!node)
            return true;
        if (node->val > max || node->val < min)
            return false;
        return (node->val == std::numeric_limits<int>::min() ? !node->left : isValidBstImpl(node->left, min, node->val - 1)) &&
               (node->val == std::numeric_limits<int>::max() ? !node->right : isValidBstImpl(node->right, node->val + 1, max));
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValidBstImpl(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    }
};
#endif //ALGORITHMICCHALLENGES_5_VALIDATEBST_H
