//https://leetcode.com/problems/count-complete-tree-nodes/
#ifndef ALGORITHMICCHALLENGES_222_COUNTCOMPLETETREENODES_H
#define ALGORITHMICCHALLENGES_222_COUNTCOMPLETETREENODES_H

#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countNodes(TreeNode* root) {
    if (!root)
        return 0;
    int cnt = 0;
    bool lastLevel = false;
    queue<TreeNode*> nodes;
    nodes.push(root);
    ++cnt;
    while (!nodes.empty()) {
        auto current = nodes.front();
        nodes.pop();
        if (current->left) {
            ++cnt;
            nodes.push(current->left);
        }
        if (current->right) {
            ++cnt;
            nodes.push(current->right);
        }
    }
    return cnt;
}

#endif //ALGORITHMICCHALLENGES_222_COUNTCOMPLETETREENODES_H
