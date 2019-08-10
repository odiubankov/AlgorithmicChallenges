#include "2_MinimalTree.h"
#include <gtest/gtest.h>

TEST(MinimalTree, one_element)
{
    auto tree = buildTreeFromSortedContainer({1});
    ASSERT_EQ(tree.head_->val_, 1);
    ASSERT_FALSE(tree.head_->left_);
    ASSERT_FALSE(tree.head_->right_);
}

TEST(MinimalTree, two_elements)
{
    auto tree = buildTreeFromSortedContainer({1, 2});
    ASSERT_EQ(tree.head_->val_, 2);
    ASSERT_EQ(tree.head_->left_->val_, 1);
    ASSERT_FALSE(tree.head_->left_->left_);
    ASSERT_FALSE(tree.head_->left_->right_);
    ASSERT_FALSE(tree.head_->right_);
}

TEST(MinimalTree, three_elements)
{
    auto tree = buildTreeFromSortedContainer({1, 2, 3});
    ASSERT_EQ(tree.head_->val_, 2);
    ASSERT_EQ(tree.head_->left_->val_, 1);
    ASSERT_FALSE(tree.head_->left_->left_);
    ASSERT_FALSE(tree.head_->left_->right_);
    ASSERT_EQ(tree.head_->right_->val_, 3);
    ASSERT_FALSE(tree.head_->right_->left_);
    ASSERT_FALSE(tree.head_->right_->right_);
}

TEST(MinimalTree, four_elements)
{
    auto tree = buildTreeFromSortedContainer({1, 2, 3, 4});
    ASSERT_EQ(tree.head_->val_, 3);
    ASSERT_EQ(tree.head_->left_->val_, 2);
    ASSERT_EQ(tree.head_->left_->left_->val_, 1);
    ASSERT_EQ(tree.head_->right_->val_, 4);
}

TEST(MinimalTree, five_elements)
{
    auto tree = buildTreeFromSortedContainer({1, 2, 3, 4, 5});
    ASSERT_EQ(tree.head_->val_, 3);
    ASSERT_EQ(tree.head_->left_->val_, 2);
    ASSERT_EQ(tree.head_->left_->left_->val_, 1);
    ASSERT_EQ(tree.head_->right_->val_, 5);
    ASSERT_EQ(tree.head_->right_->left_->val_, 4);
}
