//https://leetcode.com/problems/longest-univalue-path/description/
#ifndef ALGORITHMICCHALLENGES_687_LONGESTUNIVALUEPATH_H
#define ALGORITHMICCHALLENGES_687_LONGESTUNIVALUEPATH_H

#include <algorithm>

class SolutionLongestUnivaluePath {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    int getChildVal(int val, TreeNode* child, int& longestPath) {
        if (child) {
            auto res = longestUnivaluePathImpl(child, longestPath);
            if (val == child->val)
                return res;
        }
        return 0;
    }

    int longestUnivaluePathImpl(TreeNode* root, int& longestPath) {
        auto leftVal = getChildVal(root->val, root->left, longestPath);
        auto rightVal = getChildVal(root->val, root->right, longestPath);
        longestPath = std::max(longestPath, leftVal + rightVal);
        return 1 + std::max(leftVal, rightVal);
    }

    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        if (root)
            longestUnivaluePathImpl(root, res);
        return res;
    }
};

#endif //ALGORITHMICCHALLENGES_687_LONGESTUNIVALUEPATH_H
