#include "9_BstSequences.h"
#include <gtest/gtest.h>

TEST(BstSequences, test) {
    TreeNode* node = new TreeNode(2);
    node->left = new TreeNode(1);
    node->right = new TreeNode(3);
    std::vector<std::vector<int>> res{{2,1,3}, {2,3,1}};
    ASSERT_EQ(res, getInsertionSequences(node));
}
