// https://leetcode.com/problems/binary-tree-preorder-traversal/

#ifndef ALGORITHMICCHALLENGES_144_BINARYTREEPREORDERTRAVERSAL_1_H
#define ALGORITHMICCHALLENGES_144_BINARYTREEPREORDERTRAVERSAL_1_H

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversalRecursive(TreeNode* root) {
    vector<int> res;
    if (root) {
        res.push_back(root->val);

        auto lTraversal = preorderTraversalRecursive(root->left);
        std::move(begin(lTraversal), end(lTraversal), std::back_inserter(res));

        auto rTraversal = preorderTraversalRecursive(root->right);
        std::move(begin(rTraversal), end(rTraversal), std::back_inserter(res));
    }

    return res;
}

vector<int> preorderTraversalIterative(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> toTraverse;
    if (root)
        toTraverse.push(root);
    while (!toTraverse.empty()) {
        auto next = toTraverse.top();
        res.push_back(next->val);
        toTraverse.pop();
        if (next->right)
            toTraverse.push(next->right);
        if (next->left)
            toTraverse.push(next->left);
    }

    return res;
}

vector<int> preorderTraversal(TreeNode* root) {
//    return preorderTraversalRecursive(root);
    return preorderTraversalIterative(root);
}

#endif //ALGORITHMICCHALLENGES_144_BINARYTREEPREORDERTRAVERSAL_1_H
