#include "12_PathsWithSum.h"
#include <gtest/gtest.h>
#include <limits>
#include <queue>

TEST(PathsWithSum, test) {
    SolutionPathSum s;
    auto n10 = new TreeNode(10);
    auto n5 = new TreeNode(5);
    n10->left = n5;
    auto nm3 = new TreeNode(-3);
    n10->right = nm3;
    auto n3 = new TreeNode(3);
    n5->left = n3;
    auto n2 = new TreeNode(2);
    n5->right = n2;
    nm3->right = new TreeNode(11);
    n3->left = new TreeNode(3);
    n3->right = new TreeNode(-2);
    n2->right = new TreeNode(1);
    ASSERT_EQ(3, s.pathSum(n10, 8));
}

namespace {
    TreeNode* createNode(int val) {
        if (val == std::numeric_limits<int>::min())
            return nullptr;
        else
            return new TreeNode(val);
    }
}


TEST(PathsWithSum, test2) {
    std::vector<int> treeValues{ 5,4,8,11,std::numeric_limits<int>::min(),13,4,7,2,std::numeric_limits<int>::min(),std::numeric_limits<int>::min(),5,1 };
    std::queue<TreeNode*> treeNodes;
    auto valIt = begin(treeValues);
    auto root = new TreeNode(*valIt);
    ++valIt;
    treeNodes.push(root);
    for(;;) {
        if (treeNodes.front()) {
            treeNodes.front()->left = createNode(*valIt);
            treeNodes.push(treeNodes.front()->left);
        } else {
            treeNodes.push(nullptr);
        }
        if (++valIt == end(treeValues))
            break;
        if (treeNodes.front()) {
            treeNodes.front()->right = createNode(*valIt);
            treeNodes.push(treeNodes.front()->right);
        } else {
            treeNodes.push(nullptr);
        }
        if (++valIt == end(treeValues))
            break;
        treeNodes.pop();
    }
    SolutionPathSum s;
    ASSERT_EQ(3, s.pathSum(root, 22));
}
