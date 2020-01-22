//https://leetcode.com/problems/path-sum-iii/
#ifndef ALGORITHMICCHALLENGES_12_PATHSWITHSUM_H
#define ALGORITHMICCHALLENGES_12_PATHSWITHSUM_H

#include "DataStructures/TreeNode.h"
#include <unordered_map>

using namespace std;

class SolutionPathSum {
    using PrefixSumsT = unordered_map<int, int>;

    int getSumCnt(TreeNode* node, PrefixSumsT& prefixSums, int targetSum, int totalSum) {
        if (!node)
            return 0;
        totalSum += node->val;
        int cnt = prefixSums[totalSum - targetSum];
        ++prefixSums[totalSum];
        cnt += getSumCnt(node->left, prefixSums, targetSum, totalSum);
        cnt += getSumCnt(node->right, prefixSums, targetSum, totalSum);
        --prefixSums[totalSum];
        return cnt;
    }

public:
    int pathSum(TreeNode* root, int sum) {
        PrefixSumsT prefixSums;
        prefixSums[0] = 1;
        return getSumCnt(root, prefixSums, sum, 0);
    }
};
#endif //ALGORITHMICCHALLENGES_12_PATHSWITHSUM_H
