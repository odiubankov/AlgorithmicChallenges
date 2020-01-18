//https://leetcode.com/problems/count-complete-tree-nodes/
#ifndef ALGORITHMICCHALLENGES_222_COUNTCOMPLETETREENODES_H
#define ALGORITHMICCHALLENGES_222_COUNTCOMPLETETREENODES_H

#include <queue>
#include <math.h>

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

bool checkExists(TreeNode* node, int level, int lastLevelMaxCnt, int item) {
    int l = 0, r = lastLevelMaxCnt - 1;
    int pivot = 0;
    for (int i = 1; i < level; ++i) {
        pivot = l + (r - l) / 2;
        if (item <= pivot) {
            node = node->left;
            r = pivot;
        } else {
            node = node->right;
            l = pivot + 1;
        }
    }
    return node;
}

int countNodesSmart(TreeNode* root) {
    if (!root)
        return 0;
    int levelsCnt = 0;
    auto nextNode = root;
    while (nextNode) {
        ++levelsCnt;
        nextNode = nextNode->left;
    }
    if (levelsCnt == 1)
        return 1;

    int lastLevelMaxCnt = pow(2, levelsCnt - 1);
    int l = 0, r = lastLevelMaxCnt-1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (checkExists(root, levelsCnt, lastLevelMaxCnt, m)) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return (lastLevelMaxCnt - 1) + l;
}

#endif //ALGORITHMICCHALLENGES_222_COUNTCOMPLETETREENODES_H
