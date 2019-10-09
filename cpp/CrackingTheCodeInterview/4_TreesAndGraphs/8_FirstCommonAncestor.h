//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
#ifndef ALGORITHMICCHALLENGES_8_FIRSTCOMMONANCESTOR_H
#define ALGORITHMICCHALLENGES_8_FIRSTCOMMONANCESTOR_H

#include "DataStructures/TreeNode.h"
#include <vector>
#include <queue>
#include <unordered_map>

class SolutionLowestCommonAncestor {
    std::vector<TreeNode*> getPathIter(TreeNode* root, TreeNode* node) {
        if (!root)
            return {};

        std::queue<TreeNode*> nodes;
        std::unordered_map<TreeNode*, TreeNode*> parents;
        nodes.push(root);
        parents.emplace(root, nullptr);
        while (!nodes.empty()) {
            auto current = nodes.front();
            if (current == node) {
                std::vector<TreeNode*> path;
                while (current) {
                    path.push_back(current);
                    current = parents[current];
                }
                return path;
            }
            nodes.pop();
            if (current->left) {
                parents[current->left] = current;
                nodes.push(current->left);
            }
            if (current->right) {
                parents[current->right] = current;
                nodes.push(current->right);
            }
        }

        return {};
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto pathP = getPathIter(root, p);
        auto pathQ = getPathIter(root, q);
        std::sort(begin(pathP), end(pathP));
        for (auto n : pathQ)
            if (std::binary_search(begin(pathP), end(pathP), n))
                return n;
        return nullptr;
    }
};

#endif //ALGORITHMICCHALLENGES_8_FIRSTCOMMONANCESTOR_H
