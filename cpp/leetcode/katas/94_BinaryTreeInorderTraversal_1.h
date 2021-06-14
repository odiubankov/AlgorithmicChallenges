//https://leetcode.com/problems/binary-tree-inorder-traversal/

#ifndef ALGORITHMICCHALLENGES_94_BINARYTREEINORDERTRAVERSAL_1_H
#define ALGORITHMICCHALLENGES_94_BINARYTREEINORDERTRAVERSAL_1_H

vector<int> inorderTraversalRecursive(TreeNode* root) {
    vector<int> res;
    if (root) {
        res = inorderTraversalRecursive(root->left);
        res.push_back(root->val);
        auto rTraversal = inorderTraversalRecursive(root->right);
        std::move(begin(rTraversal), end(rTraversal), std::back_inserter(res));
    }
    return res;
}

vector<int> inorderTraversalIterative(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> toTraverse;
    toTraverse.push(root);
    while (!toTraverse.empty()) {
        auto nextItem = toTraverse.top();
        while (nextItem->left) {
            toTraverse.push(nextItem->left);
            nextItem = nextItem->left;
        }
        res.push(nextItem->val);
        if (nextItem->right)
            toTraverse.push(nextItem->right);
    }

    return res;
}

vector<int> inorderTraversal(TreeNode* root) {
    return inorderTraversalRecursive(root);
}

#endif //ALGORITHMICCHALLENGES_94_BINARYTREEINORDERTRAVERSAL_1_H
