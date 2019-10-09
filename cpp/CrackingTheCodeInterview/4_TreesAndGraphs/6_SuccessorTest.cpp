#include "6_Successor.h"
#include <gtest/gtest.h>

TEST(InorderSuccessor, test) {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    SolutionInorderSuccessor s;
    ASSERT_EQ(root, s.inorderSuccessor(root, root->left));
}

TEST(InorderSuccessor, test2) {
    TreeNode* root = new TreeNode(5);
    auto node3 = new TreeNode(3);
    root->left = node3;
    root->right = new TreeNode(6);
    auto node2 = new TreeNode(2);
    node3->left = node2;
    node3->right = new TreeNode(4);
    node2->left = new TreeNode(1);

    SolutionInorderSuccessor s;
    ASSERT_EQ(nullptr, s.inorderSuccessor(root, root->right));
}
