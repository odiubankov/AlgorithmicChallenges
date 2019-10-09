#include "8_FirstCommonAncestor.h"
#include <gtest/gtest.h>

TEST(FirstCommonAncestor, test) {
    TreeNode* root = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    root->left = node5;
    TreeNode* node1 = new TreeNode(1);
    root->right = node1;
    node5->left = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    node5->right = node2;
    node2->left = new TreeNode(7);
    node2->right = new TreeNode(4);
    node1->left = new TreeNode(0);
    node1->right = new TreeNode(8);
    SolutionLowestCommonAncestor s;
    ASSERT_EQ(root, s.lowestCommonAncestor(root, node5, root));
}

TEST(FirstCommonAncestor, test2) {
    TreeNode* root = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    root->left = node5;
    TreeNode* node1 = new TreeNode(1);
    root->right = node1;
    node5->left = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    node5->right = node2;
    node2->left = new TreeNode(7);
    node2->right = new TreeNode(4);
    node1->left = new TreeNode(0);
    node1->right = new TreeNode(8);
    SolutionLowestCommonAncestor s;
    ASSERT_EQ(node5, s.lowestCommonAncestor(root, node5, node2->right));
}
