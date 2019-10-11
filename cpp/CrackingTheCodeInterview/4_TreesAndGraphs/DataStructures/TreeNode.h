#ifndef ALGORITHMICCHALLENGES_TREENODE_H
#define ALGORITHMICCHALLENGES_TREENODE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


#endif //ALGORITHMICCHALLENGES_TREENODE_H
