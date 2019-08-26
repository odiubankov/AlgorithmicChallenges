#include "4_CheckBalanced.h"
#include <gtest/gtest.h>

TEST(CheckBalanced, unbalanced)
{
//    10
//    /\
//   8  22
//      /\
//     11 30
//        /
//       25
    auto node25 = std::make_shared<BstNode>(25);
    auto node11 = std::make_shared<BstNode>(11);
    auto node30 = std::make_shared<BstNode>(30);
    node30->left_ = node25;
    auto node8 = std::make_shared<BstNode>(8);
    auto node22 = std::make_shared<BstNode>(22);
    node22->left_ = node11;
    node22->right_ = node30;
    auto node10 = std::make_shared<BstNode>(10);
    node10->left_ = node8;
    node10->right_ = node22;
    Bst bst;
    bst.head_ = node10;
    ASSERT_FALSE(checkBalanced(bst));
}

TEST(CheckBalanced, balanced)
{
//    10
//    /\
//   8  22
//  /   /\
// 3   11 30

    auto node3 = std::make_shared<BstNode>(3);
    auto node11 = std::make_shared<BstNode>(11);
    auto node30 = std::make_shared<BstNode>(30);
    auto node8 = std::make_shared<BstNode>(8);
    node8->left_ = node3;
    auto node22 = std::make_shared<BstNode>(22);
    node22->left_ = node11;
    node22->right_ = node30;
    auto node10 = std::make_shared<BstNode>(10);
    node10->left_ = node8;
    node10->right_ = node22;
    Bst bst;
    bst.head_ = node10;
    ASSERT_TRUE(checkBalanced(bst));
}
