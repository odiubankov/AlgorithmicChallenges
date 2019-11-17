#include "889_ConstructBinaryTreeFromPreorderandPostorderTraversal.h"
#include <gtest/gtest.h>

TEST(ConstructBinaryTree, test) {
    ASSERT_TRUE(SolutionPrePostTraversal{}.constructFromPrePost({1,2,4,5,3,6,7}, {4,5,2,6,7,3,1}));
}

TEST(ConstructBinaryTree, test2) {
    ASSERT_TRUE(SolutionPrePostTraversal{}.constructFromPrePost({2,1,3}, {3,1,2}));
}
