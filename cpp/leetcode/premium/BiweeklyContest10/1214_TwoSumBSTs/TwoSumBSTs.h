//https://leetcode.com/contest/biweekly-contest-10/problems/two-sum-bsts/
#ifndef ALGORITHMICCHALLENGES_TWO_SUM_BSTS_H
#define ALGORITHMICCHALLENGES_TWO_SUM_BSTS_H

class SolutionTwoSumBSTs {
public:
    struct TreeNode {
        int val{0};
        TreeNode *left{nullptr};
        TreeNode *right{nullptr};
        TreeNode(int x)
            : val{x}, left{nullptr}, right{nullptr}
        {}
    };

private:
    bool hasVal(TreeNode *root, int val) {
        if (!root)
            return false;
        else if (root->val == val)
            return true;
        else if (root->val > val)
            return hasVal(root->left, val);
        else
            return hasVal(root->right, val);
    }

public:
    bool twoSumBSTs(TreeNode *root1, TreeNode *root2, int target) {
        if (!root1 || !root2)
            return false;

        auto valueToLook = target - root1->val;
        if (hasVal(root2, valueToLook))
            return true;
        else
            return twoSumBSTs(root1->left, root2, target) || twoSumBSTs(root1->right, root2, target);
    }
};

#endif //ALGORITHMICCHALLENGES_TWO_SUM_BSTS_H
