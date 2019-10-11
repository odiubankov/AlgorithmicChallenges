//https://leetcode.com/problems/path-sum-iii/
#ifndef ALGORITHMICCHALLENGES_12_PATHSWITHSUM_H
#define ALGORITHMICCHALLENGES_12_PATHSWITHSUM_H

#include "DataStructures/TreeNode.h"

class SolutionPathSum {
    int sumWithNode(TreeNode* root, int sum) {
        if (!root)
            return 0;
        auto diff = sum - root->val;
        return sumWithNode(root->left, diff) +
            sumWithNode(root->right, diff) +
            (root->val == sum ? 1 : 0);
    }

public:
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        auto diff = sum - root->val;
        return sumWithNode(root->left, diff)
            + sumWithNode(root->right, diff)
            + pathSum(root->left, sum)
            + pathSum(root->right, sum)
            + (root->val == sum ? 1 : 0);
    }
};
#endif //ALGORITHMICCHALLENGES_12_PATHSWITHSUM_H
