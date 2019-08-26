#include "3_ListOfDepth.h"
#include <gtest/gtest.h>

namespace{

Bst createBst(){
    //    10
    //    /\
    //   8  22
    //  /   /\
    // 3   11 30
    //        /
    //       25
    auto node25 = std::make_shared<BstNode>(25);
    auto node3 = std::make_shared<BstNode>(3);
    auto node11 = std::make_shared<BstNode>(11);
    auto node30 = std::make_shared<BstNode>(30);
    node30->left_ = node25;
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
    return bst;
}

}

TEST(ListOfDepthRecursion, test)
{
    auto lod = getListOfDepthRecursion(createBst());
    ASSERT_EQ(4, lod.size());
    ASSERT_EQ((std::vector<int>{10}), lod[0]);
    ASSERT_EQ((std::vector<int>{8, 22}), lod[1]);
    ASSERT_EQ((std::vector<int>{3, 11, 30}), lod[2]);
    ASSERT_EQ((std::vector<int>{25}), lod[3]);
}

TEST(ListOfDepthIterative, test)
{
    auto lod = getListOfDepthIterative(createBst());
    ASSERT_EQ(4, lod.size());
    ASSERT_EQ((std::vector<int>{10}), lod[0]);
    ASSERT_EQ((std::vector<int>{8, 22}), lod[1]);
    ASSERT_EQ((std::vector<int>{3, 11, 30}), lod[2]);
    ASSERT_EQ((std::vector<int>{25}), lod[3]);
}
