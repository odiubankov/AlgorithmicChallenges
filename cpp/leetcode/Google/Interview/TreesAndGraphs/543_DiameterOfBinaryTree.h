//https://leetcode.com/problems/diameter-of-binary-tree/
#ifndef ALGORITHMICCHALLENGES_543_DIAMETEROFBINARYTREE_H
#define ALGORITHMICCHALLENGES_543_DIAMETEROFBINARYTREE_H

#include <limits>
#include <algorithm>
using namespace std;

class SolutionDiameterofBinaryTree {
public:
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x)
            : val(x), left(nullptr), right(nullptr)
        {}
    };

    int getMaxLength(TreeNode* node, int& maxDiameter) {
        if (!node)
            return 0;
        int maxLeft = getMaxLength(node->left, maxDiameter);
        int maxRight = getMaxLength(node->right, maxDiameter);
        maxDiameter = max(1 + maxLeft + maxRight, maxDiameter);
        return 1 + max(maxLeft, maxRight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int maxDiameter = 0;
        getMaxLength(root, maxDiameter);
        return maxDiameter - 1;
    }
};

#endif //ALGORITHMICCHALLENGES_543_DIAMETEROFBINARYTREE_H
