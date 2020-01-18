#include "222_CountCompleteTreeNodes.h"
#include <gtest/gtest.h>

TEST(CountCompleteTreeNodes, test) {
    auto h = new TreeNode(1);
    h->left = new TreeNode(2);
    ASSERT_EQ(2, countNodesSmart(h));
}

TEST(CountCompleteTreeNodes, test2) {
    auto h = new TreeNode(1);
    h->left = new TreeNode(2);
    h->right = new TreeNode(3);
    ASSERT_EQ(3, countNodesSmart(h));
}
