//https://leetcode.com/problems/binary-tree-maximum-path-sum/
#ifndef ALGORITHMICCHALLENGES_124_BINARYTREEMAXIMUMPATHSUM_H
#define ALGORITHMICCHALLENGES_124_BINARYTREEMAXIMUMPATHSUM_H

#include <unordered_map>
using namespace std;

class SolutionMaxPathSum {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    int maxSumImpl(TreeNode* root, int& maxSum) {
        if (!root)
            return 0;
        int goLeft = max(maxSumImpl(root->left, maxSum), 0);
        int goRight = max(maxSumImpl(root->right, maxSum), 0);
        int sumWithNode = root->val + goLeft + goRight;
        maxSum = max(maxSum, sumWithNode);
        return root->val + max(goLeft, goRight);
    }

    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        int maxSum = numeric_limits<int>::min();
        maxSumImpl(root, maxSum);
        return maxSum;
    }
};

#endif //ALGORITHMICCHALLENGES_124_BINARYTREEMAXIMUMPATHSUM_H
