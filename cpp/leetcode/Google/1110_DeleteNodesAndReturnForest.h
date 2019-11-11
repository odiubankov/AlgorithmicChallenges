//https://leetcode.com/problems/delete-nodes-and-return-forest/
#ifndef ALGORITHMICCHALLENGES_1110_DELETENODESANDRETURNFOREST_H
#define ALGORITHMICCHALLENGES_1110_DELETENODESANDRETURNFOREST_H

#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct NodeInfo{
    TreeNode* n;
    TreeNode* parent;
    bool left;
    NodeInfo(TreeNode* n_, TreeNode* parent_, bool left_) : n(n_), parent(parent_), left(left_) {}
};

vector<TreeNode*> delNodes(TreeNode* root, const vector<int>& to_delete) {
    unordered_set<int> delSet;
    for (auto d : to_delete)
        delSet.insert(d);

    queue<NodeInfo> toProcess;
    toProcess.emplace(root, nullptr, false);
    vector<TreeNode*> roots;
    while (!toProcess.empty()) {
        auto nodeInfo = toProcess.front();
        toProcess.pop();
        if (!nodeInfo.n)
            continue;
        bool stay = delSet.find(nodeInfo.n->val) == end(delSet);
        if (stay) {
            if (!nodeInfo.parent)
                roots.push_back(nodeInfo.n);
        } else {
            if (nodeInfo.parent) {
                if (nodeInfo.left)
                    nodeInfo.parent->left = nullptr;
                else
                    nodeInfo.parent->right = nullptr;
            }
        }
        TreeNode* parent = stay ? nodeInfo.n : nullptr;
        toProcess.emplace(nodeInfo.n->left, parent, true);
        toProcess.emplace(nodeInfo.n->right, parent, false);
    }
    return roots;
}

#endif //ALGORITHMICCHALLENGES_1110_DELETENODESANDRETURNFOREST_H
