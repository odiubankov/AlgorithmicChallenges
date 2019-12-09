//https://leetcode.com/problems/flip-equivalent-binary-trees/
#ifndef ALGORITHMICCHALLENGES_951_FLIPEQUIVALENTBINARYTREES_H
#define ALGORITHMICCHALLENGES_951_FLIPEQUIVALENTBINARYTREES_H

class SolutionFlipEquiv {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return true;
        if (!root1 || !root2)
            return false;
        if (root1->val != root2->val)
            return false;
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
            (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};

#endif //ALGORITHMICCHALLENGES_951_FLIPEQUIVALENTBINARYTREES_H
