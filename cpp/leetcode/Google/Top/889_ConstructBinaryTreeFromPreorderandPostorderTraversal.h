//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
#ifndef ALGORITHMICCHALLENGES_889_CONSTRUCTBINARYTREEFROMPREORDERANDPOSTORDERTRAVERSAL_H
#define ALGORITHMICCHALLENGES_889_CONSTRUCTBINARYTREEFROMPREORDERANDPOSTORDERTRAVERSAL_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class SolutionPrePostTraversal {
public:

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using TraversalT = vector<int>;
using TraversalItT = TraversalT::const_iterator;

TreeNode* constructFromPrePost(const TraversalItT& preB, const TraversalItT& preE, const TraversalItT& postB, const TraversalItT& postE) {
    if (preB == preE)
        return nullptr;
    auto node = new TreeNode{*preB};
    auto preIt = preB + 1;
    if (preIt == preE)
        return node;
    auto postIt = postE - 2;
    if (*preIt == *postIt) { // node has only one child;
        node->left = constructFromPrePost(preIt, preE, postB, postIt + 1);
    } else { //node has two children
        //left child subsequence
        auto leftChildPreB = preIt;
        auto leftChildPreE = find(preIt, preE, *postIt);
        auto rightChildPreB = leftChildPreE;
        auto rightChildPreE = preE;
        auto rightChildPostB = find(postB, postIt, *preIt) + 1;
        auto rightChildPostE = postIt + 1;
        auto leftChildPostB = postB;
        auto leftChildPostE = rightChildPostB;
        node->left = constructFromPrePost(leftChildPreB, leftChildPreE, leftChildPostB, leftChildPostE);
        node->right = constructFromPrePost(rightChildPreB, rightChildPreE, rightChildPostB, rightChildPostE);
    }
    return node;
}

TreeNode* constructFromPrePost(const vector<int>& pre, const vector<int>& post) {
    return constructFromPrePost(begin(pre), end(pre), begin(post), end(post));
}
};

#endif //ALGORITHMICCHALLENGES_889_CONSTRUCTBINARYTREEFROMPREORDERANDPOSTORDERTRAVERSAL_H
